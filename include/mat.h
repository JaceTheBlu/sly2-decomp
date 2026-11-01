#ifndef MAT_H
#define MAT_H
#include "vec.h"
#include "vu0.h"
/* Matrices are stored as quadword rows: the VU0 code reads them as rows (r), the scalar code as floats (mat). */
struct MATRIX3                  /* 3x3 rotation, rows padded to 4 floats (48 bytes) */
{
    union
    {
        float mat[3][4];
        vu0_qword r[3];
    };
} __attribute__((aligned(16)));

struct MATRIX4
{
    union
    {
        float mat[4][4];
        vu0_qword r[4];
    };
} __attribute__((aligned(16)));

#ifndef __cplusplus
typedef struct MATRIX3 MATRIX3;
typedef struct MATRIX4 MATRIX4;
#endif
#endif
