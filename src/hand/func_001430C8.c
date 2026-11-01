#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct P { char pad[0x10F8]; void *p10F8; int x10FC; };
extern float D_002BD2C0;
extern float D_002BD2C4;
qword func_001A62E8(void *p);
qword func_001A6F00(void *pm, struct P *p, qword v);
float func_002458F0(float y, float x);
static __inline__ float GAbs(float g) { return g < 0.0f ? -g : g; }
int func_001430C8(struct P *p)
{
    int n;
    int r;
    if (p->p10F8) {
        qword v = func_001A6F00(0, p, func_001A62E8(p->p10F8));
        float g = func_002458F0(GetY(v), GetX(v));
        float a = __builtin_fabsf(g);
        if (a < D_002BD2C0) n = 0;
        else if (D_002BD2C4 < a) n = 3;
        else if (0.0f < g) n = 1;
        else n = 2;
    }
    r = 8;
    switch (p->x10FC) {
    case -1: case 0: break;
    case 1: r = 0x10 << n; break;
    case 2: r = 0x100 << n; break;
    case 3: r = 0x1000; break;
    case 4: r = 0x100; break;
    }
    return r;
}
