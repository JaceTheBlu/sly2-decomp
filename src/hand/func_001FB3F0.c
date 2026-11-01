#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct P { char pad[0x1C]; int n1C; qword v; };
extern qword D_002A2DD0;
int func_0011D4D0(float, float, float);
void func_001FB658(struct P *, int, int);
static inline int FNear(qword a, qword b)
{
    return func_0011D4D0(GetX(a), GetX(b), 0.0001f) && func_0011D4D0(GetY(a), GetY(b), 0.0001f) && func_0011D4D0(GetZ(a), GetZ(b), 0.0001f);
}
void func_001FB3F0(struct P *p, qword v)
{
    p->v = v;
    if (!FNear(D_002A2DD0, v)) func_001FB658(p, 0x200, 0x200);
    else if (!p->n1C) func_001FB658(p, 0x200, 0);
}
