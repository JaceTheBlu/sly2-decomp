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
int func_001880D8(struct JOY *p)
{
    float g;
    if (!p->dirY) {
        int grf = PvAllocSwCopyImpl__FiPv(p, 0x5000);
        if (grf & 0x1000) p->dirY = -1;
        else if (grf & 0x4000) p->dirY = 1;
        else if (p->gMag >= 0.8f && __builtin_fabsf(p->gY) > __builtin_fabsf(p->gX)) {
            if (0.0f < p->gY) p->dirY = -1;
            else p->dirY = 1;
        }
        if (p->dirY) {
            g = 0.3333f;
            p->tRepY = g;
            p->tNextY = g_clock.tFrame + g;
        }
    } else {
        int fHeld = 0;
        if (p->dirY < 0) {
            if (p->grfHeld & 0x1000) fHeld = 1;
            else if (p->gMag >= 0.25f && __builtin_fabsf(p->gY) > __builtin_fabsf(p->gX) && 0.0f < p->gY)
                fHeld = 1;
        } else {
            if (p->grfHeld & 0x4000) fHeld = 1;
            else if (p->gMag >= 0.25f && __builtin_fabsf(p->gY) > __builtin_fabsf(p->gX) && p->gY < 0.0f)
                fHeld = 1;
        }
        if (!fHeld) {
            p->dirY = 0;
        } else if (p->tNextY <= g_clock.tFrame) {
            g = GClamp(2.0f * p->tRepY / 3.0f, 0.1f, 0.3333f);
            p->tRepY = g;
            p->tNextY = g_clock.tFrame + g;
        } else {
            return 0;
        }
    }
    return p->dirY;
}
