/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_CHANGECURRENTSESSIONDAYHUMIDITYMESSAGE_PB_H_INCLUDED
#define PB_CHANGECURRENTSESSIONDAYHUMIDITYMESSAGE_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _ChangeCurrentSessionDayHumidityMessage {
    uint32_t dayNumber;
    float humidity;
/* @@protoc_insertion_point(struct:ChangeCurrentSessionDayHumidityMessage) */
} ChangeCurrentSessionDayHumidityMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define ChangeCurrentSessionDayHumidityMessage_init_default {0, 0}
#define ChangeCurrentSessionDayHumidityMessage_init_zero {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define ChangeCurrentSessionDayHumidityMessage_dayNumber_tag 2
#define ChangeCurrentSessionDayHumidityMessage_humidity_tag 3

/* Struct field encoding specification for nanopb */
extern const pb_field_t ChangeCurrentSessionDayHumidityMessage_fields[3];

/* Maximum encoded size of messages (where known) */
#define ChangeCurrentSessionDayHumidityMessage_size 11

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define CHANGECURRENTSESSIONDAYHUMIDITYMESSAGE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
