//
// Created by volodymyr on 24.04.19.
//

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <malloc.h>
#include <zconf.h>
#include <pthread.h>
#include "message_helper.h"
#include "proto/OutputMessage.pb.h"
#include "proto/pb_encode.h"
#include "proto/IncomeMessage.pb.h"
#include "proto/pb_decode.h"
#include "proto/pb_common.h"
#include "proto/pb.h"
#include "encoder/incubator/RegisterDeviceRequestMessageEncoder.h"
#include "parser/incubator/StartNewSessionWithCalendarMessageParser.h"
#include "parser/incubator/SuccessRegistrationMessageParser.h"


static void handleInputData(int32_t dataSize, char *buffer,MessageHelper *this);
static void inputDataThreadHandler(MessageHelper *this);
static bool createIncomingDataHandlerThread(MessageHelper *this);
static bool write_serial_number(pb_ostream_t *stream, const pb_field_t *field, void * const *arg);
static bool decode_send_calendar_days(pb_istream_t *stream, const pb_field_t *field, void **arg);
static bool decode_success_serial_number(pb_istream_t *stream, const pb_field_t *field, void **arg);
static char * receivedSerialNumber;
static bool addDeviceHandler(MessageHelper *this,struct DeviceHandler * handler);
static SendCalendarMessage_IncubationDayInformationMessage * incubationDayInformationMessages;
static pthread_mutex_t mutex;
static bool readBytesFromSocket(int socketId, uint16_t length,void *buffer);
static void *incomingDataThread(void *arg){
    MessageHelper *messageHelper = (MessageHelper *) arg;
    inputDataThreadHandler(messageHelper);
}
static bool sendMessage(MessageHelper *this, OutputMessage message){
    pthread_mutex_trylock(&mutex);
    uint8_t *buffer = (uint8_t *) malloc(this->bufferSize);
    pb_ostream_t ostream = pb_ostream_from_buffer(buffer,this->bufferSize);
    pb_encode(&ostream,OutputMessage_fields,&message);
    uint32_t messageSize = (uint32_t) ostream.bytes_written;
    uint8_t  messageSizeArray[4];
    messageSizeArray[0] = (messageSize >> 24) & 0xFF;
    messageSizeArray[1] = (messageSize >> 16) & 0xFF;
    messageSizeArray[2] = (messageSize >> 8) & 0xFF;
    messageSizeArray[3] = messageSize & 0xFF;
    send(this->connectionId,messageSizeArray, sizeof(messageSize),0);
    ssize_t count = send(this->connectionId, buffer, ostream.bytes_written, 0);
    free(buffer);
    pthread_mutex_unlock(&mutex);

    return count==ostream.bytes_written;
}
static bool connectToServer(MessageHelper *this){
    struct sockaddr_in serv_addr;
    if((this->connectionId = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return false;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(this->port);

    if(inet_pton(AF_INET, this->serverAddress, &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return false;
    }

    if( connect(this->connectionId, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        return false;
    }
    return createIncomingDataHandlerThread(this);

}
void handleInputData(int32_t dataSize, char *buffer,MessageHelper *this) {
    pb_istream_t istream = pb_istream_from_buffer((const pb_byte_t *) buffer, dataSize);
    IncomeMessage incomeMessage = {};
    incomeMessage.incubatorMessagePayload.startNewSessionWithCalendarMessage = START_NEW_SESSION_WITH_CALENDAR_MESSAGE_init_parser;
    incomeMessage.incubatorMessagePayload.startNewSessionWithCalendarMessage.days.arg = incubationDayInformationMessages;
    incomeMessage.incubatorMessagePayload.successRegistrationMessage= REGISTRATION_SUCCESS_NOTIFICATION_MESSAGE_init_parser;
    incomeMessage.incubatorMessagePayload.successRegistrationMessage.serialNumber.arg = receivedSerialNumber;
    pb_decode(&istream,IncomeMessage_fields,&incomeMessage);
    int32_t inReplyTo = incomeMessage.has_inReplyTo ? incomeMessage.inReplyTo : NO_REPLY;
    int32_t replyWith = incomeMessage.has_replyWith ? incomeMessage.replyWith : NO_REPLY;
    if(this->deviceHandlers[incomeMessage.deviceId]!=NULL) {
        DeviceHandler *deviceHandler = this->deviceHandlers[incomeMessage.deviceId];
        if (incomeMessage.has_incubatorMessagePayload) {
            deviceHandler->baseMessageHandler(deviceHandler,replyWith,inReplyTo,&incomeMessage.incubatorMessagePayload);
        }
    }

}

void inputDataThreadHandler(MessageHelper *this) {
    int32_t  n;
    while (true) {
        pthread_mutex_trylock(&mutex);
        uint32_t length = 0;
        char * buffer = 0;
        readBytesFromSocket(this->connectionId,sizeof(length),(void*)(&length));
        length = (length & 0x000000ff) << 24u
                | (length & 0x0000ff00) << 8u
                | (length & 0x00ff0000) >> 8u
                | (length & 0xff000000) >> 24u;
        buffer = (char *) malloc(length * sizeof(char));
        readBytesFromSocket(this->connectionId,length,(void*)buffer);
        handleInputData(length,buffer,this);
        free(buffer);
        pthread_mutex_unlock(&mutex);
    }
    if(n < 0)
    {
        printf("\n Read error \n");
    }
}

bool createIncomingDataHandlerThread(MessageHelper *this) {
    pthread_t handlerThread;
    pthread_mutex_init(&mutex, NULL);
    if(pthread_create(&handlerThread, NULL, incomingDataThread, (void *)this)) {

        fprintf(stderr, "Error creating thread\n");
        return false;

    }
    return true;
}

bool addDeviceHandler(MessageHelper *this, struct DeviceHandler *handler) {
    if (this->devicesCount<this->devicesArraySize){
        this->deviceHandlers[this->devicesCount] = handler;
        handler->deviceId = this->devicesCount;
        this->devicesCount++;
    } else{
        struct DeviceHandler **newArray = realloc(this->deviceHandlers, (this->devicesArraySize+START_DEVICE_ARRAY_SIZE)*
                                                                        sizeof(struct DeviceHandler *));
        if(newArray){
            this->deviceHandlers = newArray;
            this->deviceHandlers[this->devicesCount] = handler;
            handler->deviceId = this->devicesCount;
            this->devicesCount++;
        } else{
            return false;
        }
    }
    return true;
}
MessageHelper *initMessageHelper(char *serverAddress, uint16_t port, uint16_t bufferSize) {
    MessageHelper *messageHelper = (MessageHelper*) malloc(sizeof(MessageHelper));
    messageHelper->serverAddress = serverAddress;
    messageHelper->bufferSize = bufferSize;
    messageHelper->port = port;
    messageHelper->sendMessage = sendMessage;
    messageHelper->devicesArraySize = START_DEVICE_ARRAY_SIZE;
    messageHelper->deviceHandlers = (DeviceHandler**) malloc(messageHelper->devicesArraySize * sizeof(DeviceHandler*));
    messageHelper->addDeviceHandler = addDeviceHandler;
    bool status = connectToServer(messageHelper);
    if(!status) {
        return NULL;
    }
    return messageHelper;
    }
bool readBytesFromSocket(int socketId, uint16_t length, void *buffer) {
    uint16_t bytesRead = 0;
    uint16_t result;
    while (bytesRead < length){
        result = read(socketId,buffer+bytesRead, length - bytesRead);
        if(result < 1){
            return false;
        }
        bytesRead += result;
    }
    return true;

}