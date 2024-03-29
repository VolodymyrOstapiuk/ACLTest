/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_NEWSESSIONSTARTEDMESSAGE_PB_H_INCLUDED
#define PB_NEWSESSIONSTARTEDMESSAGE_PB_H_INCLUDED
#include "pb.h"

#include "BirdType.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _NewSessionStartedMessage {
    bool has_calendarId;
    uint32_t calendarId;
    bool has_birdType;
    BirdType birdType;
/* @@protoc_insertion_point(struct:NewSessionStartedMessage) */
} NewSessionStartedMessage;

/* Default values for struct fields */

/* Initializer values for message structs */
#define NewSessionStartedMessage_init_default    {false, 0, false, _BirdType_MIN}
#define NewSessionStartedMessage_init_zero       {false, 0, false, _BirdType_MIN}

/* Field tags (for use in manual encoding/decoding) */
#define NewSessionStartedMessage_calendarId_tag  1
#define NewSessionStartedMessage_birdType_tag    2

/* Struct field encoding specification for nanopb */
extern const pb_field_t NewSessionStartedMessage_fields[3];

/* Maximum encoded size of messages (where known) */
#define NewSessionStartedMessage_size            8

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define NEWSESSIONSTARTEDMESSAGE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
