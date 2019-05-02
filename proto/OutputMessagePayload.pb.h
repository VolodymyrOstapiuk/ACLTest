/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Wed May  1 00:47:17 2019. */

#ifndef PB_OUTPUTMESSAGEPAYLOAD_PB_H_INCLUDED
#define PB_OUTPUTMESSAGEPAYLOAD_PB_H_INCLUDED
#include "pb.h"

#include "IncubationSessionCurrentHumidityMessage.pb.h"

#include "IncubationSessionCurrentTemperatureMessage.pb.h"

#include "RegisterDeviceRequestMessage.pb.h"

#include "CriticalHumidityValueMessage.pb.h"

#include "CriticalTemperatureValueMessage.pb.h"

#include "IncubatorOpenEventMessage.pb.h"

#include "IncubatorRotationEventMessage.pb.h"

#include "IncubatorVentilationEventMessage.pb.h"

#include "NewSessionStartedMessage.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _OutputMessagePayload {
    bool has_currentHumidityMessage;
    IncubationSessionCurrentHumidityMessage currentHumidityMessage;
    bool has_currentTemperatureMessage;
    IncubationSessionCurrentTemperatureMessage currentTemperatureMessage;
    bool has_registerDeviceRequestMessage;
    RegisterDeviceRequestMessage registerDeviceRequestMessage;
    bool has_criticalHumidityValueMessage;
    CriticalHumidityValueMessage criticalHumidityValueMessage;
    bool has_criticalTemperatureValueMessage;
    CriticalTemperatureValueMessage criticalTemperatureValueMessage;
    bool has_incubatorOpenEventMessage;
    IncubatorOpenEventMessage incubatorOpenEventMessage;
    bool has_incubatorRotationEventMessage;
    IncubatorRotationEventMessage incubatorRotationEventMessage;
    bool has_incubatorVentilationEventMessage;
    IncubatorVentilationEventMessage incubatorVentilationEventMessage;
    bool has_newSessionStartedMessage;
    NewSessionStartedMessage newSessionStartedMessage;
/* @@protoc_insertion_point(struct:OutputMessagePayload) */
} OutputMessagePayload;

/* Default values for struct fields */

/* Initializer values for message structs */
#define OutputMessagePayload_init_default        {false, IncubationSessionCurrentHumidityMessage_init_default, false, IncubationSessionCurrentTemperatureMessage_init_default, false, RegisterDeviceRequestMessage_init_default, false, CriticalHumidityValueMessage_init_default, false, CriticalTemperatureValueMessage_init_default, false, IncubatorOpenEventMessage_init_default, false, IncubatorRotationEventMessage_init_default, false, IncubatorVentilationEventMessage_init_default, false, NewSessionStartedMessage_init_default}
#define OutputMessagePayload_init_zero           {false, IncubationSessionCurrentHumidityMessage_init_zero, false, IncubationSessionCurrentTemperatureMessage_init_zero, false, RegisterDeviceRequestMessage_init_zero, false, CriticalHumidityValueMessage_init_zero, false, CriticalTemperatureValueMessage_init_zero, false, IncubatorOpenEventMessage_init_zero, false, IncubatorRotationEventMessage_init_zero, false, IncubatorVentilationEventMessage_init_zero, false, NewSessionStartedMessage_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define OutputMessagePayload_currentHumidityMessage_tag 1
#define OutputMessagePayload_currentTemperatureMessage_tag 2
#define OutputMessagePayload_registerDeviceRequestMessage_tag 4
#define OutputMessagePayload_criticalHumidityValueMessage_tag 6
#define OutputMessagePayload_criticalTemperatureValueMessage_tag 7
#define OutputMessagePayload_incubatorOpenEventMessage_tag 8
#define OutputMessagePayload_incubatorRotationEventMessage_tag 9
#define OutputMessagePayload_incubatorVentilationEventMessage_tag 10
#define OutputMessagePayload_newSessionStartedMessage_tag 11

/* Struct field encoding specification for nanopb */
extern const pb_field_t OutputMessagePayload_fields[10];

/* Maximum encoded size of messages (where known) */
#define OutputMessagePayload_size                (83 + RegisterDeviceRequestMessage_size)

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define OUTPUTMESSAGEPAYLOAD_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
