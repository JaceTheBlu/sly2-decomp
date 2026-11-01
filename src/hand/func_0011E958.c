#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
static inline float sqrtf_(float x) { float r; __asm__ __volatile__("sqrt.s %0, %1" : "=&f"(r) : "f"(x)); return r; }
float func_002458F0(float y, float x);
float RadNormalize__Ff(float g);
void func_0011E958(qword v, float *pradPan, float *pradTilt)
{
    if (pradPan)
        *pradPan = RadNormalize__Ff(func_002458F0(GetY(v), GetX(v)));
    if (pradTilt)
        *pradTilt = RadNormalize__Ff(func_002458F0(GetZ(v), sqrtf_(GetX(v) * GetX(v) + GetY(v) * GetY(v))));
}
