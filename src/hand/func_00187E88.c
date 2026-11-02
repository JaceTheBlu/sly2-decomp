#include "clock.h"
struct JOY {
    char pad[0x1024]; int dirX; int dirY; float tNextX; float tRepX; float tNextY; float tRepY;
    float gX; float gY; float gMag; char p1[0x6C]; int grfHeld;
};
extern struct CLOCK g_clock;
int PvAllocSwCopyImpl__FiPv(struct JOY *p, int grf);
static __inline__ float GClamp(float g, float lo, float hi)
{
    if (g < lo) return lo;
    if (g > hi) return hi;
    return g;
}
int func_00187E88(struct JOY *p)
{
    float g;
    if (!p->dirX) {
        int grf = PvAllocSwCopyImpl__FiPv(p, 0xA000);
        if (grf & 0x8000) p->dirX = -1;
        else if (grf & 0x2000) p->dirX = 1;
        else if (p->gMag >= 0.8f && __builtin_fabsf(p->gX) > __builtin_fabsf(p->gY)) {
            if (p->gX < 0.0f) p->dirX = -1;
            else p->dirX = 1;
        }
        if (p->dirX) {
            g = 0.3333f;
            p->tRepX = g;
            p->tNextX = g_clock.tFrame + g;
        }
    } else {
        int fHeld = 0;
        if (p->dirX < 0) {
            if (p->grfHeld & 0x8000) fHeld = 1;
            else if (p->gMag >= 0.25f && __builtin_fabsf(p->gX) > __builtin_fabsf(p->gY) && p->gX < 0.0f)
                fHeld = 1;
        } else {
            if (p->grfHeld & 0x2000) fHeld = 1;
            else if (p->gMag >= 0.25f && __builtin_fabsf(p->gX) > __builtin_fabsf(p->gY) && 0.0f < p->gX)
                fHeld = 1;
        }
        if (!fHeld) {
            p->dirX = 0;
        } else if (p->tNextX <= g_clock.tFrame) {
            g = GClamp(2.0f * p->tRepX / 3.0f, 0.1f, 0.3333f);
            p->tRepX = g;
            p->tNextX = g_clock.tFrame + g;
        } else {
            return 0;
        }
    }
    return p->dirX;
}
