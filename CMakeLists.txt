cmake_minimum_required(VERSION 3.9)
project(IncubatorTestClient C)

set(CMAKE_C_STANDARD 99)
set(src ./)
file(GLOB source_files
        "*.h"
        "*.c" "proto/*.c"
        "proto/*.h"
        "encoder/incubator/*.c"
        "encoder/incubator/*.h"
        "parser/incubator/*.c"
        "parser/incubator/*.h"
        )
find_package (Threads)
add_executable(IncubatorTestClient ${source_files} message_helper.c message_helper.h IncubatorHelper.c IncubatorHelper.h DeviceHandler.h config.h parser/incubator/StartNewSessionWithCalendarMessageParser.c parser/incubator/StartNewSessionWithCalendarMessageParser.h parser/incubator/SuccessRegistrationMessageParser.c parser/incubator/SuccessRegistrationMessageParser.h encoder/incubator/RegisterDeviceRequestMessageEncoder.c encoder/incubator/RegisterDeviceRequestMessageEncoder.h)
target_link_libraries (IncubatorTestClient ${CMAKE_THREAD_LIBS_INIT})