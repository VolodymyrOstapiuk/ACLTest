/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_INCUBATORINCOMEMESSAGEPAYLOAD_PB_H_INCLUDED
#define PB_INCUBATORINCOMEMESSAGEPAYLOAD_PB_H_INCLUDED
#include "pb.h"

#include "ChangeCurrentSessionDayHumidityMessage.pb.h"

#include "ChangeCurrentSessionDayParametersMessage.pb.h"

#include "ChangeCurrentSessionDayRotationCountMessage.pb.h"

#include "ChangeCurrentSessionDayTemperatureMessage.pb.h"

#include "ChangeCurrentSessionDayVentillationCountMessage.pb.h"

#include "ChangeCurrentSessionDayVentillationDurationMessage.pb.h"

#include "ForceRotateEggsMessage.pb.h"

#include "ForceVentilateIncubatorMessage.pb.h"

#include "RegistrationSuccessNotificationMessage.pb.h"

#include "StartNewSessionWithBirdTypeMessage.pb.h"

#include "StartNewSessionWithCalendarMessage.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _IncubatorIncomeMessagePayload {
    bool has_changeDayHumidityMessage;
    ChangeCurrentSessionDayHumidityMessage changeDayHumidityMessage;
    bool has_changeDayParametersMessage;
    ChangeCurrentSessionDayParametersMessage changeDayParametersMessage;
    bool has_changeDayRotationCountMessage;
    ChangeCurrentSessionDayRotationCountMessage changeDayRotationCountMessage;
    bool has_changeDayTemperatureMessage;
    ChangeCurrentSessionDayTemperatureMessage changeDayTemperatureMessage;
    bool has_changeDayVentillationCountMessage;
    ChangeCurrentSessionDayVentillationCountMessage changeDayVentillationCountMessage;
    bool has_changeDayVentillationDurationMessage;
    ChangeCurrentSessionDayVentillationDurationMessage changeDayVentillationDurationMessage;
    bool has_forceRotateEggsMessage;
    ForceRotateEggsMessage forceRotateEggsMessage;
    bool has_forceVentilateIncubatorMessage;
    ForceVentilateIncubatorMessage forceVentilateIncubatorMessage;
    bool has_startNewSessionWithBirdTypeMessage;
    StartNewSessionWithBirdTypeMessage startNewSessionWithBirdTypeMessage;
    bool has_startNewSessionWithCalendarMessage;
    StartNewSessionWithCalendarMessage startNewSessionWithCalendarMessage;
    bool has_successRegistrationMessage;
    RegistrationSuccessNotificationMessage successRegistrationMessage;
/* @@protoc_insertion_point(struct:IncubatorIncomeMessagePayload) */
} IncubatorIncomeMessagePayload;

/* Default values for struct fields */

/* Initializer values for message structs */
#define IncubatorIncomeMessagePayload_init_default {false, ChangeCurrentSessionDayHumidityMessage_init_default, false, ChangeCurrentSessionDayParametersMessage_init_default, false, ChangeCurrentSessionDayRotationCountMessage_init_default, false, ChangeCurrentSessionDayTemperatureMessage_init_default, false, ChangeCurrentSessionDayVentillationCountMessage_init_default, false, ChangeCurrentSessionDayVentillationDurationMessage_init_default, false, ForceRotateEggsMessage_init_default, false, ForceVentilateIncubatorMessage_init_default, false, StartNewSessionWithBirdTypeMessage_init_default, false, StartNewSessionWithCalendarMessage_init_default, false, RegistrationSuccessNotificationMessage_init_default}
#define IncubatorIncomeMessagePayload_init_zero  {false, ChangeCurrentSessionDayHumidityMessage_init_zero, false, ChangeCurrentSessionDayParametersMessage_init_zero, false, ChangeCurrentSessionDayRotationCountMessage_init_zero, false, ChangeCurrentSessionDayTemperatureMessage_init_zero, false, ChangeCurrentSessionDayVentillationCountMessage_init_zero, false, ChangeCurrentSessionDayVentillationDurationMessage_init_zero, false, ForceRotateEggsMessage_init_zero, false, ForceVentilateIncubatorMessage_init_zero, false, StartNewSessionWithBirdTypeMessage_init_zero, false, StartNewSessionWithCalendarMessage_init_zero, false, RegistrationSuccessNotificationMessage_init_zero}

/* Field tags (for use in manual encoding/decoding) */
#define IncubatorIncomeMessagePayload_changeDayHumidityMessage_tag 3
#define IncubatorIncomeMessagePayload_changeDayParametersMessage_tag 4
#define IncubatorIncomeMessagePayload_changeDayRotationCountMessage_tag 5
#define IncubatorIncomeMessagePayload_changeDayTemperatureMessage_tag 6
#define IncubatorIncomeMessagePayload_changeDayVentillationCountMessage_tag 7
#define IncubatorIncomeMessagePayload_changeDayVentillationDurationMessage_tag 8
#define IncubatorIncomeMessagePayload_forceRotateEggsMessage_tag 9
#define IncubatorIncomeMessagePayload_forceVentilateIncubatorMessage_tag 10
#define IncubatorIncomeMessagePayload_startNewSessionWithBirdTypeMessage_tag 11
#define IncubatorIncomeMessagePayload_startNewSessionWithCalendarMessage_tag 12
#define IncubatorIncomeMessagePayload_successRegistrationMessage_tag 13

/* Struct field encoding specification for nanopb */
extern const pb_field_t IncubatorIncomeMessagePayload_fields[12];

/* Maximum encoded size of messages (where known) */
#define IncubatorIncomeMessagePayload_size       (145 + StartNewSessionWithCalendarMessage_size + RegistrationSuccessNotificationMessage_size)

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define INCUBATORINCOMEMESSAGEPAYLOAD_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif