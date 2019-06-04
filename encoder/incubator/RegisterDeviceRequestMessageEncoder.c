//
// Created by volodymyr on 02.05.19.
//

#include "RegisterDeviceRequestMessageEncoder.h"
#include "../../proto/pb_encode.h"

bool write_serial_number(pb_ostream_t *stream, const pb_field_t *field, void *const *arg);

bool write_serial_number(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    char *str = (char*) arg[0];
    if (!pb_encode_tag_for_field(stream, field))
        return false;
    return pb_encode_string(stream, (uint8_t*)str, strlen(str));
}

const RegisterDeviceRequestMessage REGISTER_DEVICE_REQUEST_MESSAGE_init_encoder = {.serialNumber={.funcs={.encode=write_serial_number}}};