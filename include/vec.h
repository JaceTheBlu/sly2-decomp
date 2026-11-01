#ifndef VEC_H
#define VEC_H
#include "common.h"
/* 16-byte (quadword) aligned on the PS2; only x/y/z are meaningful, w is the 4th lane that quadword
   stores write */
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct VECTOR4 { float x, y, z, w; } __attribute__((aligned(16)));

#ifndef __cplusplus
typedef struct VECTOR VECTOR;
typedef struct VECTOR4 VECTOR4;
#endif
#endif
