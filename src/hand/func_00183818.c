#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct O { char pad[0x10C]; int n10C; };
struct J { char pad[0x240]; qword v240; char pad2[0x103C - 0x250]; float g103C; int n1040; };
extern qword func_001A62E8(void *p);
extern qword *func_001A6318(void *p);
extern float func_002458F0(float y, float x);
void func_00183818(struct O *p, struct J *pj, qword *pv, float *pg)
{
    float g = 0.0f;
    qword d;
    if (p->n10C == 0)
        g = pj->g103C;
    d = *func_001A6318(p);
    if (pv) {
        qword a, s, r;
        union { qword q; float f[4]; } u;
        a = func_001A62E8(p);
        __asm__("vsub.xyzw %0, %1, %2" : "=j"(r) : "j"(a), "j"(pj->v240));
        __asm__("qmtc2.ni %1, %0" : "=j"(s) : "r"(g));
        u.q = s;
        __asm__("vadda.xyzw ACC, %1, $vf0\n\tvmaddx.xyzw %0, %2, %3x" : "=j"(r) : "j"(r), "j"(d), "j"(s));
        *pv = r;
    }
    if (pg) {
        float gAng = func_002458F0(GetY(d), GetX(d));
        if (pj->n1040 == 1)
            gAng += 3.14159265f;
        *pg = gAng;
    }
}
