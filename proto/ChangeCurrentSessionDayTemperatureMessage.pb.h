/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_CHANGECURRENTSESSIONDAYTEMPERATUREMESSAGE_PB_H_INCLUDED
#define PB_CHANGECURRENTSESSIONDAYTEMPERATUREMESSAGE_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _ChangeCurrentSessionDayTemperatureMessage {
    uint32_t dayNumber;
    float temperature;
/* @@protoc_insertion_point(struct:ChangeCurrentSessionDayTemperatureMessage) */
} ChangeCurrentSessionDayTemperatureMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define ChangeCurrentSessionDayTemperatureMessage_init_default {0, 0}
#define ChangeCurrentSessionDayTemperatureMessage_init_zero {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define ChangeCurrentSessionDayTemperatureMessage_dayNumber_tag 2
#define ChangeCurrentSessionDayTemperatureMessage_temperature_tag 3

/* Struct field encoding specification for nanopb */
extern const pb_field_t ChangeCurrentSessionDayTemperatureMessage_fields[3];

/* Maximum encoded size of messages (where known) */
#define ChangeCurrentSessionDayTemperatureMessage_size 11

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define CHANGECURRENTSESSIONDAYTEMPERATUREMESSAGE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
