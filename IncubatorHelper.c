//
// Created by volodymyr on 30.04.19.
//

#include <stdlib.h>
#include "proto/IncubatorIncomeMessagePayload.pb.h"
#include "proto/OutputMessage.pb.h"
#include "IncubatorHelper.h"
#include "encoder/incubator/RegisterDeviceRequestMessageEncoder.h"

static bool sendCurrentTemperature(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo,  float temperature );
static bool sendCurrentHumidity(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, float humidity);
static bool sendCriticalHumidityNotification(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo,float humidity,  float neededLevelHumidity);
static bool sendCriticalTemperatureNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo,float temperature, float neededLevelTemperature);
static bool sendOpenEventNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, bool isOpened);
static bool sendRotationEventNotification(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo,uint8_t rotationCount);
static bool sendVentilationEventNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, uint32_t duration);
static bool sendNewSessionStartedNotificationWithBirdType(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, BirdType birdType);
static bool
sendNewSessionStartedNotificationWithCalendarId(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, uint32_t calendarId);
static bool registerDevice(IncubatorHandler *this);
static bool sendIncubatorOutputMessage(IncubatorHandler *this,IncubatorOutputMessagePayload payload,int32_t replyWith, int32_t inReplyTo);
static void baseMessageHandler(DeviceHandler *this,int32_t replyWith, int32_t inReplyTo, void *payload);
void baseMessageHandler(DeviceHandler *this, int32_t replyWith, int32_t inReplyTo, void *payload) {
    IncubatorIncomeMessagePayload *incomeMessagePayload = (IncubatorIncomeMessagePayload *) payload;
    if(incomeMessagePayload->has_successRegistrationMessage){
        this->callListener(this,ON_REGISTRATION_SUCCESS,replyWith,inReplyTo,&incomeMessagePayload->successRegistrationMessage);
    } else if (incomeMessagePayload->has_changeDayHumidityMessage){
        this->callListener(this,ON_REQUEST_TO_CHANGE_SESSION_DAY_HUMIDITY,replyWith,inReplyTo,&incomeMessagePayload->changeDayHumidityMessage);
    } else if (incomeMessagePayload->has_changeDayTemperatureMessage){
        this->callListener(this,ON_REQUEST_TO_CHANGE_SESSION_DAY_TEMPERATURE,replyWith,inReplyTo,&incomeMessagePayload->changeDayTemperatureMessage);
    }  else if (incomeMessagePayload->has_changeDayParametersMessage){
        this->callListener(this,ON_REQUEST_TO_CHANGE_SESSION_DAY_PARAMETERS,replyWith,inReplyTo,&incomeMessagePayload->changeDayParametersMessage);
    }  else if (incomeMessagePayload->has_changeDayVentillationDurationMessage){
        this->callListener(this,ON_REQUEST_TO_CHANGE_SESSION_DAY_VENTILATION_DURATION,replyWith,inReplyTo,&incomeMessagePayload->changeDayVentillationDurationMessage);
    }  else if (incomeMessagePayload->has_changeDayVentillationCountMessage){
        this->callListener(this,ON_REQUEST_TO_CHANGE_SESSION_DAY_VENTILATION_COUNT,replyWith,inReplyTo,&incomeMessagePayload->changeDayVentillationCountMessage);
    }  else if (incomeMessagePayload->has_changeDayRotationCountMessage){
        this->callListener(this,ON_REQUEST_TO_CHANGE_SESSION_DAY_ROTATION_COUNT,replyWith,inReplyTo,&incomeMessagePayload->changeDayRotationCountMessage);
    }  else if (incomeMessagePayload->has_forceVentilateIncubatorMessage){
        this->callListener(this,ON_REQUEST_TO_FORCE_VENTILATE,replyWith,inReplyTo,&incomeMessagePayload->forceVentilateIncubatorMessage);
    }  else if (incomeMessagePayload->has_forceRotateEggsMessage){
        this->callListener(this,ON_REQUEST_TO_FORCE_ROTATE,replyWith,inReplyTo,&incomeMessagePayload->forceRotateEggsMessage);
    }  else if (incomeMessagePayload->has_startNewSessionWithBirdTypeMessage){
        this->callListener(this,ON_REQUEST_TO_START_NEW_SESSION_WITH_KNOWN_BIRD_TYPE,replyWith,inReplyTo,&incomeMessagePayload->startNewSessionWithBirdTypeMessage);
    }   else if (incomeMessagePayload->has_startNewSessionWithCalendarMessage){
        this->callListener(this,ON_REQUEST_TO_START_NEW_SESSION_WITH_NEW_CALENDAR,replyWith,inReplyTo,&incomeMessagePayload->startNewSessionWithCalendarMessage);
    }

}


IncubatorHandler initIncubatorHandler(MessageHelper *messageHelper, const char *serialNumber) {
    IncubatorHandler handler = {};
    handler.baseHandler = initDeviceHandler(messageHelper, serialNumber,INCUBATOR_EVENTS_COUNT,ON_REGISTRATION_SUCCESS);
    handler.baseHandler.baseMessageHandler = baseMessageHandler;
    handler.sendOpenEventNotification = sendOpenEventNotification;
    handler.sendCriticalTemperatureNotification = sendCriticalTemperatureNotification;
    handler.sendCriticalHumidityNotification = sendCriticalHumidityNotification;
    handler.sendNewSessionStartedNotificationWithCalendarId = sendNewSessionStartedNotificationWithCalendarId;
    handler.sendNewSessionStartedNotificationWithBirdType = sendNewSessionStartedNotificationWithBirdType;
    handler.sendCurrentHumidity = sendCurrentHumidity;
    handler.sendCurrentTemperature = sendCurrentTemperature;
    handler.sendVentilationEventNotification = sendVentilationEventNotification;
    handler.sendRotationEventNotification = sendRotationEventNotification;
    handler.registerDevice = registerDevice;
    return handler;
};

bool registerDevice(IncubatorHandler *this) {
    RegisterDeviceRequestMessage registerDeviceRequestMessage = REGISTER_DEVICE_REQUEST_MESSAGE_init_encoder;
    registerDeviceRequestMessage.serialNumber.arg = (void *) this->baseHandler.serialNumber;
    IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
    payload.registerDeviceRequestMessage = registerDeviceRequestMessage;
    payload.has_registerDeviceRequestMessage = true;
    return sendIncubatorOutputMessage(this,payload,this->baseHandler.messageNumber,NO_REPLY);
}

bool sendCurrentTemperature(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, float temperature) {
    if(this->baseHandler.registered) {
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        IncubationSessionCurrentTemperatureMessage temperatureMessage = {.temperature=temperature};
        payload.currentTemperatureMessage = temperatureMessage;
        payload.has_currentTemperatureMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendCurrentHumidity(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, float humidity) {
    if(this->baseHandler.registered) {
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        IncubationSessionCurrentHumidityMessage humidityMessage = {.humidity=humidity};
        payload.currentHumidityMessage = humidityMessage;
        payload.has_currentHumidityMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendCriticalHumidityNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, float humidity, float neededLevelHumidity) {
    if(this->baseHandler.registered) {
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        CriticalHumidityValueMessage humidityMessage = {.currentHumidity=humidity, .neededHumidity=neededLevelHumidity};
        payload.criticalHumidityValueMessage = humidityMessage;
        payload.has_criticalHumidityValueMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendCriticalTemperatureNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, float temperature, float neededLevelTemperature) {
    if(this->baseHandler.registered) {
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        CriticalTemperatureValueMessage temperatureValueMessage = {.currentTemperature=temperature, .neededTemperature=neededLevelTemperature};
        payload.criticalTemperatureValueMessage = temperatureValueMessage;
        payload.has_criticalTemperatureValueMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;

}

bool sendOpenEventNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, bool isOpened) {
    if(this->baseHandler.registered) {
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        IncubatorOpenEventMessage openEventMessage = {.isOpened=isOpened};
        payload.incubatorOpenEventMessage = openEventMessage;
        payload.has_incubatorOpenEventMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendRotationEventNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, uint8_t rotationCount) {
    if(this->baseHandler.registered) {
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        IncubatorRotationEventMessage rotationEventMessage = {.count = rotationCount};
        payload.incubatorRotationEventMessage = rotationEventMessage;
        payload.has_incubatorRotationEventMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendVentilationEventNotification(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, uint32_t duration) {
    if(this->baseHandler.registered) {

        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        IncubatorVentilationEventMessage ventilationEventMessage = {.duration=duration};
        payload.incubatorVentilationEventMessage = ventilationEventMessage;
        payload.has_incubatorVentilationEventMessage = true;

        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendNewSessionStartedNotificationWithBirdType(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, BirdType birdType) {
    if(this->baseHandler.registered) {

        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        NewSessionStartedMessage sessionStartedMessage = NewSessionStartedMessage_init_zero;
        sessionStartedMessage.birdType = birdType;
        sessionStartedMessage.has_birdType = true;
        payload.newSessionStartedMessage = sessionStartedMessage;
        payload.has_newSessionStartedMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}

bool sendNewSessionStartedNotificationWithCalendarId(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo, uint32_t calendarId) {
    if(this->baseHandler.registered) {

        OutputMessage outputMessage = OutputMessage_init_zero;
        IncubatorOutputMessagePayload payload = IncubatorOutputMessagePayload_init_zero;
        NewSessionStartedMessage sessionStartedMessage = NewSessionStartedMessage_init_zero;
        sessionStartedMessage.calendarId = calendarId;
        sessionStartedMessage.has_calendarId = true;
        payload.newSessionStartedMessage = sessionStartedMessage;
        payload.has_newSessionStartedMessage = true;
        return sendIncubatorOutputMessage(this,payload,replyWith,inReplyTo);
    }
    return false;
}
bool  sendIncubatorOutputMessage(IncubatorHandler *this, IncubatorOutputMessagePayload payload, int32_t replyWith,
                                int32_t inReplyTo) {
    OutputMessage outputMessage = OutputMessage_init_zero;
    outputMessage.incubatorOutputMessagePayload = payload;
    outputMessage.has_incubatorOutputMessagePayload = true;
    if(replyWith!=NO_REPLY){
        outputMessage.replyWith = (uint32_t) replyWith;
        outputMessage.has_replyWith = true;
    }
    if(inReplyTo !=NO_REPLY){
        outputMessage.inReplyTo = (uint32_t) inReplyTo;
        outputMessage.has_inReplyTo = true;
    }
    outputMessage.deviceId = this->baseHandler.deviceId;
    bool status = this->baseHandler.messageHelper->sendMessage(this->baseHandler.messageHelper,outputMessage);
    this->baseHandler.messageNumber++;
    return status;
}


