#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct O { char pad[0x10C]; float g10C; };
struct J { char pad[0x240]; qword v240; char pad2[0x103C - 0x250]; float g103C; int n1040; };
extern qword func_001A62E8(void *p);
extern qword func_0011E1A0(float a, float b, float c);
void func_00183540(struct O *p, float g, struct J *pj, qword *pv, float *pg)
{
    float gPan = g / p->g10C;
    float gR = p->g10C + pj->g103C;
    if (pv) {
        *pv = QwSub(QwAdd(func_001A62E8(p), func_0011E1A0(gPan, gR, 0.0f)), pj->v240);
    }
    if (pg) {
        if (pj->n1040 == 1)
            gPan += 3.14159265f;
        *pg = gPan;
    }
}
