/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#include "ChangeCurrentSessionDayTemperatureMessage.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t ChangeCurrentSessionDayTemperatureMessage_fields[3] = {
    PB_FIELD(  2, UINT32  , REQUIRED, STATIC  , FIRST, ChangeCurrentSessionDayTemperatureMessage, dayNumber, dayNumber, 0),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, ChangeCurrentSessionDayTemperatureMessage, temperature, dayNumber, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */