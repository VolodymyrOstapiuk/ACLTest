//
// Created by volodymyr on 02.05.19.
//

#include <stdlib.h>
#include "SuccessRegistrationMessageParser.h"
#include "../../proto/pb_decode.h"
#include "../../message_helper.h"

static bool decode_success_serial_number(pb_istream_t *stream, const pb_field_t *field, void **arg);

bool decode_success_serial_number(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    arg[0] = malloc(stream->bytes_left);
    pb_read(stream,arg[0],stream->bytes_left);
}




const RegistrationSuccessNotificationMessage REGISTRATION_SUCCESS_NOTIFICATION_MESSAGE_init_parser = {.serialNumber={.funcs={.decode=decode_success_serial_number}}};
