#include "clock.h"
// Interpolate alternating noise samples with smoothstep.
extern CLOCK g_clock __asm__("g_clock");
float UNoise(int n);
static inline float GSmooth(float s)
{
    float twice=s+s;
    register float square __asm__("$f3")=s;
    __asm__("mul.s %0,%0,%0":"+f"(square));
    return square*(3.0f-twice);
}
static inline float Product(float a,float b)
{
    __asm__("mul.s %0,%1,%0":"+f"(b):"f"(a));
    return b;
}
float UNoise(float gFreq, float gPhase, float u1)
{
    float uRandom = u1;
    float t = gFreq * 2.0f * g_clock.t + gPhase;
    int n = (int)t;
    float u0 = UNoise(n);
    u1 = UNoise(n + 1);
    if (n & 1) {
        u0 *= uRandom;
        u1 = uRandom * (u1 - 1.0f) + 1.0f;
    } else {
        u1 *= uRandom;
        u0 = uRandom * (u0 - 1.0f) + 1.0f;
    }
    return u0+Product(GSmooth(t-n),u1-u0);
}
