#include "clock.h"
extern CLOCK g_clock __asm__("g_clock");
struct CIRCLER { char pad[0x50]; float radsSpeed; };
float GModPositive(float, float);
float UCompleteCircler(CIRCLER *pcircler)
{
    float angle = g_clock.t * pcircler->radsSpeed;
    return GModPositive(angle, 6.28318530718f) * 0.159154943092f;
}
