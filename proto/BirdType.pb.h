/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.3 at Thu May  2 00:38:34 2019. */

#ifndef PB_BIRDTYPE_PB_H_INCLUDED
#define PB_BIRDTYPE_PB_H_INCLUDED
#include "pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _BirdType {
    BirdType_Chicken = 1,
    BirdType_Duck = 2,
    BirdType_Goose = 3
} BirdType;
#define _BirdType_MIN BirdType_Chicken
#define _BirdType_MAX BirdType_Goose
#define _BirdType_ARRAYSIZE ((BirdType)(BirdType_Goose+1))

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
