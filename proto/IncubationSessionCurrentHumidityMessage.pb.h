/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_INCUBATIONSESSIONCURRENTHUMIDITYMESSAGE_PB_H_INCLUDED
#define PB_INCUBATIONSESSIONCURRENTHUMIDITYMESSAGE_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _IncubationSessionCurrentHumidityMessage {
    float humidity;
/* @@protoc_insertion_point(struct:IncubationSessionCurrentHumidityMessage) */
} IncubationSessionCurrentHumidityMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define IncubationSessionCurrentHumidityMessage_init_default {0}
#define IncubationSessionCurrentHumidityMessage_init_zero {0}

/* Field tags (for use in manual encoding/decoding) */
#define IncubationSessionCurrentHumidityMessage_humidity_tag 2

/* Struct field encoding specification for nanopb */
extern const pb_field_t IncubationSessionCurrentHumidityMessage_fields[2];

/* Maximum encoded size of messages (where known) */
#define IncubationSessionCurrentHumidityMessage_size 5

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define INCUBATIONSESSIONCURRENTHUMIDITYMESSAGE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
