//
// Created by volodymyr on 30.04.19.
//

#include <zconf.h>
#include <stdlib.h>
#include "DeviceHandler.h"
static bool callListener(DeviceHandler *this,uint32_t eventType,int32_t replyWith, int32_t inReplyTo,void *payload);
static bool registerListener(DeviceHandler *this,uint32_t eventType, MessageHandler listener);
bool callListener(DeviceHandler *this, uint32_t eventType, int32_t replyWith, int32_t inReplyTo, void *payload) {
    if(this->handlers[eventType]!=NULL){
        this->handlers[eventType](this,replyWith,inReplyTo,payload);
        return true;
    }
    return false;
}

bool registerListener(DeviceHandler *this, uint32_t eventType, MessageHandler listener) {
    if(eventType<this->eventsCount){
        this->handlers[eventType] = listener;
    }
    return false;
}

DeviceHandler initDeviceHandler(MessageHelper *helper, const char *serialNumber, uint32_t eventsCount, uint32_t registrationEventId) {
    DeviceHandler handler = {};
    handler.messageHelper = helper;
    handler.serialNumber = serialNumber;
    handler.handlers = (MessageHandler *) malloc(eventsCount*sizeof(MessageHandler));
    handler.eventsCount = eventsCount;
    handler.callListener = callListener;
    handler.registerListener = registerListener;
    handler.registerListener(&handler,registrationEventId,registrationDefaultHandler);
    return handler;
}
void registrationDefaultHandler(DeviceHandler *handler, int32_t replyWith, int32_t inReplyTo, void *message){
    handler->registered = true;
}
