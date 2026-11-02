#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct SOURCE;
struct P { char pad[0x1C]; struct SOURCE *source; qword v; };
extern qword D_002A2DD0;
int func_0011D4D0(float, float, float);
void func_001FB658(struct P *, unsigned short, unsigned short);
static inline int FNear(qword a, qword b)
{
    return func_0011D4D0(GetX(a), GetX(b), 0.0001f) && func_0011D4D0(GetY(a), GetY(b), 0.0001f) && func_0011D4D0(GetZ(a), GetZ(b), 0.0001f);
}
void func_001FB2F8(struct P *p, struct SOURCE *source)
{
    p->source = source;
    if (source) func_001FB658(p, 0x200, 0x200);
    else if (FNear(D_002A2DD0, p->v)) func_001FB658(p, 0x200, 0);
}
