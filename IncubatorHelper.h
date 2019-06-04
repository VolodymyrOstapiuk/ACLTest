//
// Created by volodymyr on 30.04.19.
//

#ifndef INCUBATORTESTCLIENT_INCUBATORHELPER_H
#define INCUBATORTESTCLIENT_INCUBATORHELPER_H

#include <stdint.h>
#include <stdbool.h>
#include <zconf.h>
#include "DeviceHandler.h"
#include "proto/BirdType.pb.h"
typedef enum {
    ON_REQUEST_TO_CHANGE_SESSION_DAY_HUMIDITY = 0,
    ON_REQUEST_TO_CHANGE_SESSION_DAY_TEMPERATURE,
    ON_REQUEST_TO_CHANGE_SESSION_DAY_PARAMETERS,
    ON_REQUEST_TO_CHANGE_SESSION_DAY_ROTATION_COUNT,
    ON_REQUEST_TO_CHANGE_SESSION_DAY_VENTILATION_DURATION,
    ON_REQUEST_TO_CHANGE_SESSION_DAY_VENTILATION_COUNT,
    ON_REQUEST_TO_FORCE_ROTATE,
    ON_REQUEST_TO_FORCE_VENTILATE,
    ON_REQUEST_TO_START_NEW_SESSION_WITH_KNOWN_BIRD_TYPE,
    ON_REQUEST_TO_START_NEW_SESSION_WITH_NEW_CALENDAR,
    ON_REGISTRATION_SUCCESS,
    INCUBATOR_EVENTS_COUNT
} IncubatorEvents;
typedef struct IncubatorHandler IncubatorHandler;
struct IncubatorHandler{
    DeviceHandler baseHandler;
    bool (*sendCurrentTemperature)(IncubatorHandler *this, int32_t replyWith, int32_t inReplyTo,float temperature );
    bool (*sendCurrentHumidity)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo, float humidity);
    bool (*sendCriticalHumidityNotification)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo,float humidity, float neededLevelHumidity);
    bool (*sendCriticalTemperatureNotification)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo,float temperature, float neededLevelTemperature);
    bool (*sendOpenEventNotification)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo, bool isOpened);
    bool (*sendRotationEventNotification)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo,uint8_t rotationCount);
    bool (*sendVentilationEventNotification)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo, uint32_t duration);
    bool (*sendNewSessionStartedNotificationWithBirdType)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo, BirdType birdType);
    bool (*sendNewSessionStartedNotificationWithCalendarId)(IncubatorHandler *this,int32_t replyWith, int32_t inReplyTo, uint32_t calendarId);

    bool (*registerDevice)(IncubatorHandler *this);
};
IncubatorHandler initIncubatorHandler(MessageHelper *messageHelper, const char *serialNumber);

#endif //INCUBATORTESTCLIENT_INCUBATORHELPER_H
