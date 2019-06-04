//
// Created by volodymyr on 30.04.19.
//

#include <stdint.h>
#include "message_helper.h"
#ifndef INCUBATORTESTCLIENT_DEVICEHANDLER_H
#define INCUBATORTESTCLIENT_DEVICEHANDLER_H

struct DeviceHandler{
    struct MessageHelper *messageHelper;
    bool registered;
    void (**handlers)(struct DeviceHandler *handler, int32_t replyWith, int32_t inReplyTo, void *message);
    uint32_t deviceId;
    const char* serialNumber;
    uint32_t eventsCount;
    uint32_t messageNumber;
    void  (*baseMessageHandler)(struct DeviceHandler *device, int32_t replyWith, int32_t inReplyTo, void *message);
    bool (*registerListener)(struct DeviceHandler *this,uint32_t eventType,  void (*listener)(struct DeviceHandler *handler, int32_t replyWith, int32_t inReplyTo, void *message));
    bool (*callListener)(struct DeviceHandler *this,uint32_t eventType,int32_t replyWith, int32_t inReplyTo,void *payload);
};
typedef struct DeviceHandler DeviceHandler;
typedef void (*MessageHandler)(DeviceHandler *handler, int32_t replyWith, int32_t inReplyTo, void *message);

DeviceHandler initDeviceHandler(struct MessageHelper *helper, const char *serialNumber, uint32_t eventsCount, uint32_t registrationEventId);
void registrationDefaultHandler(DeviceHandler *handler, int32_t replyWith, int32_t inReplyTo, void *message);
#endif