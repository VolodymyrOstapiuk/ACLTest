/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_OUTPUTMESSAGE_PB_H_INCLUDED
#define PB_OUTPUTMESSAGE_PB_H_INCLUDED
#include "pb.h"

#include "IncubatorOutputMessagePayload.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _OutputMessage {
    uint32_t deviceId;
    bool has_incubatorOutputMessagePayload;
    IncubatorOutputMessagePayload incubatorOutputMessagePayload;
    bool has_replyWith;
    uint32_t replyWith;
    bool has_inReplyTo;
    uint32_t inReplyTo;
/* @@protoc_insertion_point(struct:OutputMessage) */
} OutputMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define OutputMessage_init_default               {0, false, IncubatorOutputMessagePayload_init_default, false, 0, false, 0}
#define OutputMessage_init_zero                  {0, false, IncubatorOutputMessagePayload_init_zero, false, 0, false, 0}

/* Field tags (for use in manual encoding/decoding) */
#define OutputMessage_deviceId_tag               1
#define OutputMessage_replyWith_tag              50
#define OutputMessage_inReplyTo_tag              51
#define OutputMessage_incubatorOutputMessagePayload_tag 2

/* Struct field encoding specification for nanopb */
extern const pb_field_t OutputMessage_fields[5];

/* Maximum encoded size of messages (where known) */
#define OutputMessage_size                       (80 + IncubationSessionCurrentHumidityMessage_size + IncubationSessionCurrentTemperatureMessage_size + RegisterDeviceRequestMessage_size + CriticalHumidityValueMessage_size + CriticalTemperatureValueMessage_size + IncubatorOpenEventMessage_size + IncubatorRotationEventMessage_size + IncubatorVentilationEventMessage_size + NewSessionStartedMessage_size)

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define OUTPUTMESSAGE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
