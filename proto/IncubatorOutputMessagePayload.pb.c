/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#include "IncubatorOutputMessagePayload.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t IncubatorOutputMessagePayload_fields[10] = {
    PB_FIELD(  1, MESSAGE , OPTIONAL, STATIC  , FIRST, IncubatorOutputMessagePayload, currentHumidityMessage, currentHumidityMessage, &IncubationSessionCurrentHumidityMessage_fields),
    PB_FIELD(  2, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, currentTemperatureMessage, currentHumidityMessage, &IncubationSessionCurrentTemperatureMessage_fields),
    PB_FIELD(  4, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, registerDeviceRequestMessage, currentTemperatureMessage, &RegisterDeviceRequestMessage_fields),
    PB_FIELD(  6, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, criticalHumidityValueMessage, registerDeviceRequestMessage, &CriticalHumidityValueMessage_fields),
    PB_FIELD(  7, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, criticalTemperatureValueMessage, criticalHumidityValueMessage, &CriticalTemperatureValueMessage_fields),
    PB_FIELD(  8, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, incubatorOpenEventMessage, criticalTemperatureValueMessage, &IncubatorOpenEventMessage_fields),
    PB_FIELD(  9, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, incubatorRotationEventMessage, incubatorOpenEventMessage, &IncubatorRotationEventMessage_fields),
    PB_FIELD( 10, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, incubatorVentilationEventMessage, incubatorRotationEventMessage, &IncubatorVentilationEventMessage_fields),
    PB_FIELD( 11, MESSAGE , OPTIONAL, STATIC  , OTHER, IncubatorOutputMessagePayload, newSessionStartedMessage, incubatorVentilationEventMessage, &NewSessionStartedMessage_fields),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(IncubatorOutputMessagePayload, currentHumidityMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, currentTemperatureMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, registerDeviceRequestMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, criticalHumidityValueMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, criticalTemperatureValueMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, incubatorOpenEventMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, incubatorRotationEventMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, incubatorVentilationEventMessage) < 65536 && pb_membersize(IncubatorOutputMessagePayload, newSessionStartedMessage) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_IncubatorOutputMessagePayload)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(IncubatorOutputMessagePayload, currentHumidityMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, currentTemperatureMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, registerDeviceRequestMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, criticalHumidityValueMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, criticalTemperatureValueMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, incubatorOpenEventMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, incubatorRotationEventMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, incubatorVentilationEventMessage) < 256 && pb_membersize(IncubatorOutputMessagePayload, newSessionStartedMessage) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_IncubatorOutputMessagePayload)
#endif


/* @@protoc_insertion_point(eof) */
