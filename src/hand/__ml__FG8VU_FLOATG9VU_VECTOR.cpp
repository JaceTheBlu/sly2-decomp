#include "vecmat.h"
typedef int qword __attribute__((mode(TI)));
qword operator*(VU_FLOAT f, VU_VECTOR v)
{
    qword r;
    __asm__("vmulx.xyzw %0, %2, %1x" : "=j"(r) : "j"(f.q), "j"(v.q));
    return r;
}
