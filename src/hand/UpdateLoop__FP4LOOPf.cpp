#include "clock.h"
extern CLOCK g_clock asm("g_clock");
struct SAI { int a; };
struct LOOP { char pad[0x1C]; int cframe; char pad1[0x34 - 0x20]; SAI sai; char pad2[0x50 - 0x38];
    float dtLoopMin; float dtLoopMax; float dtPauseMin; float dtPauseMax; float dframe; float iframe; float dtPause; float dtPauseRemaining; };
extern "C" int func_0011A1E8(SAI *psai);
extern "C" float GRandInRange__Fff(float gLow, float gHigh);
extern "C" float GModPositive__Fff(float g, float gMod);
extern "C" void SetSaiIframe__FP3SAIi(LOOP *p, int iframe);
void UpdateLoop(LOOP *ploop, float dt)
{
    if (func_0011A1E8(&ploop->sai))
        return;

    if (ploop->cframe < 2)
        return;

    if (ploop->dtPauseRemaining > 0.0f)
    {
        ploop->dtPauseRemaining -= g_clock.dt;
        return;
    }

    ploop->iframe += ploop->dframe * g_clock.dt;

    if (ploop->iframe >= (float)ploop->cframe)
    {
        float rand1 = GRandInRange__Fff(ploop->dtLoopMin, ploop->dtLoopMax);
        ploop->dframe = (float)ploop->cframe / rand1;

        float rand2 = GRandInRange__Fff(ploop->dtPauseMin, ploop->dtPauseMax);
        ploop->dtPause = rand2;
        ploop->dtPauseRemaining = rand2;
    }

    ploop->iframe = GModPositive__Fff(ploop->iframe, (float)ploop->cframe);
    SetSaiIframe__FP3SAIi(ploop, (int)ploop->iframe);
}
