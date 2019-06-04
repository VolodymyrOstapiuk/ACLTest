//
// Created by volodymyr on 02.05.19.
//

#include <stdlib.h>
#include "StartNewSessionWithCalendarMessageParser.h"
#include "../../proto/SendCalendarMessage.pb.h"
#include "../../proto/pb_decode.h"

static bool decode_send_calendar_days(pb_istream_t *stream, const pb_field_t *field, void **arg);

bool decode_send_calendar_days(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    arg[0] = malloc(stream->bytes_left/ sizeof(SendCalendarMessage_IncubationDayInformationMessage));
    SendCalendarMessage_IncubationDayInformationMessage *array = arg[0];
    uint8_t i = 0;
    while (stream->bytes_left)
    {

        if (!pb_decode(stream,SendCalendarMessage_IncubationDayInformationMessage_fields,&array[i]))
            return false;
        i++;
    }
    return true;
}

const StartNewSessionWithCalendarMessage START_NEW_SESSION_WITH_CALENDAR_MESSAGE_init_parser = {.days={.funcs={.decode =decode_send_calendar_days}}};