#include "clock.h"
extern CLOCK g_clock asm("g_clock");
struct SAI { int a; };
struct CIRCLER { char pad[0x34]; SAI sai; char pad2[0x50 - 0x38]; float radsSpeed; float radius; float duCenter; float dvCenter; };
extern "C" int func_0011A1E8(SAI *psai);
extern "C" float RadNormalize__Ff(float rad);
extern "C" void CalculateSinCos__FfPfT1(float rad, float *pgSin, float *pgCos);
extern "C" void func_001EDAD8(CIRCLER *p, float du, float dv);
void UpdateCircler(CIRCLER *pcircler, float dt)
{
    if (func_0011A1E8(&pcircler->sai))
        return;

    float angle = RadNormalize__Ff(g_clock.t * pcircler->radsSpeed);

    float sinOut;
    float cosOut;
    CalculateSinCos__FfPfT1(angle, &sinOut, &cosOut);

    sinOut = (sinOut * pcircler->radius) + pcircler->duCenter;
    cosOut = (cosOut * pcircler->radius) + pcircler->dvCenter;

    func_001EDAD8(pcircler, sinOut, cosOut);
}
