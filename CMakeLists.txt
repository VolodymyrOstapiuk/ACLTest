cmake_minimum_required(VERSION 3.9)
project(IncubatorTestClient C)

set(CMAKE_C_STANDARD 99)
set(src ./)
file(GLOB source_files
        "*.h"
        "*.c" "proto/*.c"
        "proto/*.h"
        )
find_package (Threads)
add_executable(IncubatorTestClient ${source_files} message_helper.c message_helper.h IncubatorHelper.c IncubatorHelper.h DeviceHandler.h config.h)
target_link_libraries (IncubatorTestClient ${CMAKE_THREAD_LIBS_INIT})