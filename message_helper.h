//
// Created by volodymyr on 24.04.19.
//

#ifndef INCUBATORTESTCLIENT_MESSAGE_HELPER_H
#define INCUBATORTESTCLIENT_MESSAGE_HELPER_H

#include <stdbool.h>
#include "proto/IncubationSessionCurrentTemperatureMessage.pb.h"
#include "proto/BirdType.pb.h"
#include "proto/ChangeCurrentSessionDayHumidityMessage.pb.h"
#include "proto/ChangeCurrentSessionDayParametersMessage.pb.h"
#include "proto/ChangeCurrentSessionDayRotationCountMessage.pb.h"
#include "proto/ChangeCurrentSessionDayTemperatureMessage.pb.h"
#include "proto/ChangeCurrentSessionDayVentillationCountMessage.pb.h"
#include "proto/ChangeCurrentSessionDayVentillationDurationMessage.pb.h"
#include "proto/ForceRotateEggsMessage.pb.h"
#include "proto/ForceVentilateIncubatorMessage.pb.h"
#include "proto/SendCalendarMessage.pb.h"
#include "proto/StartNewSessionMessage.pb.h"
#include "proto/RegistrationSuccessNotificationMessage.pb.h"
#include "DeviceHandler.h"
#include "proto/OutputMessage.pb.h"

#define START_DEVICE_ARRAY_SIZE 5
#define NO_REPLY (-1)
#define MAX_MESSAGE_LENGTH 2048
typedef struct MessageHelper{
    const char *serverAddress;
    uint16_t port;
    uint16_t bufferSize;
    int32_t connectionId;
    struct DeviceHandler **deviceHandlers;

    uint16_t devicesCount;
    uint16_t devicesArraySize;
    bool (*addDeviceHandler)(struct MessageHelper *this,struct DeviceHandler * handler);
    bool (*sendMessage)(struct MessageHelper *this, OutputMessage message);
} MessageHelper;
MessageHelper *initMessageHelper(char *serverAddress, uint16_t port, uint16_t bufferSize);
#endif //INCUBATORTESTCLIENT_MESSAGE_HELPER_H
