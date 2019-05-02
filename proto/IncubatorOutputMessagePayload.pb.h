/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_INCUBATOROUTPUTMESSAGEPAYLOAD_PB_H_INCLUDED
#define PB_INCUBATOROUTPUTMESSAGEPAYLOAD_PB_H_INCLUDED
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
typedef struct _IncubatorOutputMessagePayload {
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
/* @@protoc_insertion_point(struct:IncubatorOutputMessagePayload) */
} IncubatorOutputMessagePayload;

/* Default values for struct fields */

/* Initializer values for message structs */
#define IncubatorOutputMessagePayload_init_default {false, IncubationSessionCurrentHumidityMessage_init_default, false, IncubationSessionCurrentTemperatureMessage_init_default, false, RegisterDeviceRequestMessage_init_default, false, CriticalHumidityValueMessage_init_default, false, CriticalTemperatureValueMessage_init_default, false, IncubatorOpenEventMessage_init_default, false, IncubatorRotationEventMessage_init_default, false, IncubatorVentilationEventMessage_init_default, false, NewSessionStartedMessage_init_default}
#define IncubatorOutputMessagePayload_init_zero  {false, IncubationSessionCurrentHumidityMessage_init_zero, false, IncubationSessionCurrentTemperatureMessage_init_zero, false, RegisterDeviceRequestMessage_init_zero, false, CriticalHumidityValueMessage_init_zero, false, CriticalTemperatureValueMessage_init_zero, false, IncubatorOpenEventMessage_init_zero, false, IncubatorRotationEventMessage_init_zero, false, IncubatorVentilationEventMessage_init_zero, false, NewSessionStartedMessage_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define IncubatorOutputMessagePayload_currentHumidityMessage_tag 1
#define IncubatorOutputMessagePayload_currentTemperatureMessage_tag 2
#define IncubatorOutputMessagePayload_registerDeviceRequestMessage_tag 4
#define IncubatorOutputMessagePayload_criticalHumidityValueMessage_tag 6
#define IncubatorOutputMessagePayload_criticalTemperatureValueMessage_tag 7
#define IncubatorOutputMessagePayload_incubatorOpenEventMessage_tag 8
#define IncubatorOutputMessagePayload_incubatorRotationEventMessage_tag 9
#define IncubatorOutputMessagePayload_incubatorVentilationEventMessage_tag 10
#define IncubatorOutputMessagePayload_newSessionStartedMessage_tag 11

/* Struct field encoding specification for nanopb */
extern const pb_field_t IncubatorOutputMessagePayload_fields[10];

/* Maximum encoded size of messages (where known) */
#define IncubatorOutputMessagePayload_size       (83 + RegisterDeviceRequestMessage_size)

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define INCUBATOROUTPUTMESSAGEPAYLOAD_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif