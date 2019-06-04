#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include "proto/pb_decode.h"
#include "proto/SendCalendarMessage.pb.h"
#include "proto/IncomeMessage.pb.h"
#include "proto/pb_encode.h"
#include "proto/pb_common.h"
#include "proto/RegisterDeviceRequestMessage.pb.h"
#include "proto/OutputMessage.pb.h"
#include "proto/pb.h"
#include "message_helper.h"
#include "IncubatorHelper.h"

#define TYPICAL_BUFFER_SIZE 256
#define SERIAL_NUMBER "firstSerialNumber"
#define SECOND_SERIAL_NUMBER "secondSerialNumber"
#define SERVER_IP_ADDRESS "127.0.0.1"
#define SERVER_PORT 1900

void startNewSessionMessageWithBirdTypeHandler(MessageHelper *this, StartNewSessionWithBirdTypeMessage *message, int32_t inReplyTo,
                                               int32_t replyWith);
void startNewSessionMessageWithCalendarHandler(MessageHelper *this, StartNewSessionWithCalendarMessage *message,
                                               int32_t inReplyTo, int32_t replyWith);


void startNewSessionMessageWithBirdTypeHandler(MessageHelper *this, StartNewSessionWithBirdTypeMessage *message,
                                               int32_t inReplyTo, int32_t replyWith) {

}

void startNewSessionMessageWithCalendarHandler(MessageHelper *this, StartNewSessionWithCalendarMessage *message,
                                               int32_t inReplyTo, int32_t replyWith) {
    SendCalendarMessage_IncubationDayInformationMessage *incubationDayInformationMessage = (SendCalendarMessage_IncubationDayInformationMessage *) message->days.arg;
    for (int i = 0; i < message->count; ++i) {
        printf("%f",incubationDayInformationMessage->information.humidity);
    }
//    this->sendNewSessionStartedNotificationWithCalendarId(this,message->calendarId,replyWith);

}




int main(int argc, char *argv[])
{
    MessageHelper* messageHelper = initMessageHelper(SERVER_IP_ADDRESS, SERVER_PORT, TYPICAL_BUFFER_SIZE);
    IncubatorHandler incubatorHandler = initIncubatorHandler(messageHelper,SERIAL_NUMBER);
    messageHelper->addDeviceHandler(messageHelper, (struct DeviceHandler *) &incubatorHandler);
    incubatorHandler.registerDevice(&incubatorHandler);
    while(!incubatorHandler.baseHandler.registered);
    incubatorHandler.sendCurrentTemperature(&incubatorHandler,NO_REPLY,NO_REPLY,10.5);
    incubatorHandler.sendRotationEventNotification(&incubatorHandler,NO_REPLY,NO_REPLY,1);
    incubatorHandler.sendVentilationEventNotification(&incubatorHandler,NO_REPLY,NO_REPLY,10);
    incubatorHandler.sendOpenEventNotification(&incubatorHandler,NO_REPLY,NO_REPLY,true);
    incubatorHandler.sendCurrentHumidity(&incubatorHandler,NO_REPLY,NO_REPLY,20);
    IncubatorHandler anotherIncubatorHandler = initIncubatorHandler(messageHelper, SECOND_SERIAL_NUMBER);
    messageHelper->addDeviceHandler(messageHelper, (struct DeviceHandler *) &anotherIncubatorHandler);
    anotherIncubatorHandler.registerDevice(&anotherIncubatorHandler);
    while(1);
    return 0;
}