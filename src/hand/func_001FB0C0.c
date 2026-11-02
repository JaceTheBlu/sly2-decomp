#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct P { char pad[0x1C]; void *p1C; qword v20; char pad2[0x40 - 0x30]; int n40; char pad3[0x4E - 0x44]; short n4E; unsigned short f50; unsigned short n52; };
extern qword D_002A2DD0;
int func_0011D4D0(float, float, float);
void func_001FB658(struct P *, int, int);
static inline int FNear(qword a, qword b)
{
    return func_0011D4D0(GetX(a), GetX(b), 0.0001f) && func_0011D4D0(GetY(a), GetY(b), 0.0001f) && func_0011D4D0(GetZ(a), GetZ(b), 0.0001f);
}
void func_001FB0C0(struct P *p)
{
    int f = 0;
    int k;
    if (!p->n40) {
        f = p->n52 || (p->f50 & 1);
        f ^= 1;
    }
    if (!f) return;
    { int fA = p->n4E > 0; k = 0x1F1; if (fA) k = 0x1F3; }
    if (p->p1C || !FNear(D_002A2DD0, p->v20))
        k |= 0x200;
    func_001FB658(p, k, k);
}
