#include "vu0.h"
struct E { int n; int nMax; int b; };
struct Q { char pad[0x574]; struct E ae[1]; };
struct S { char p0[0x150]; int n150; int a; int i; int d; };
void func_001D4FA0(struct S *p, int n);
void func_001D3FF0(struct Q *q, struct S *p) {
    if (p->n150 != 2) {
        struct E *pe = &q->ae[p->i];
        int n = pe->n + p->d;
        pe->n = NMin(pe->nMax, n);
        func_001D4FA0(p, 2);
    }
}
