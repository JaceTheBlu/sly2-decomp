#include "clock.h"
typedef int qword __attribute__((mode(TI)));
extern struct CLOCK g_clock;
extern float D_002A53D4;
struct Q2 { qword a, b; };
struct E { qword pos; qword pad; };
struct S { char pad[0x18]; void *p18; char pad2[0x20]; float g3C; char pad3[0x10]; struct E ae[4]; unsigned int cD0; };
int func_0017DCB8(void *p);
void __1M(struct Q2 *pq);
void func_0017DD38(void *p, struct Q2 *pq);
void func_00172F10(struct S *p) {
    void *p18;
    struct E *pe;
    struct Q2 q;
    if (p->cD0 >= 4) return;
    p18 = p->p18;
    if (p->g3C == D_002A53D4) {
        if (func_0017DCB8(p18)) p->g3C = g_clock.t + 1.0f;
    }
    if (g_clock.t < p->g3C) return;
    pe = &p->ae[p->cD0++];
    if (p->cD0 >= 4) p->cD0 = 0;
    __1M(&q);
    q.b = pe->pos;
    func_0017DD38(p18, &q);
    p->g3C = D_002A53D4;
}
