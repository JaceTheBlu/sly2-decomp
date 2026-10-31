#include "clock.h"
struct VTE { short d; short pad; void (*pfn)(); };
struct O { char pad[0xC]; struct VTE *vt; };
struct X;
struct X {
    char pad[0x40]; int fl;
    char pad1[0x68 - 0x44]; struct X *f68;
    char pad2[0x94 - 0x6C]; int c94; struct X **a98;
    char pad3[0xA0 - 0x9C]; int cA0; struct X **aA4;
    char pad4[0xB0 - 0xA8]; int fB0; int fB4; struct O *pB8; struct O *pBC; struct X *fC0; int fC4; float fC8;
};
extern struct CLOCK g_clock;
extern char g_sw[];
int func_00164030(struct X *p);
void func_001A6CA8(struct X *p, int n);
void func_0020EFC0(void *pg, int n);
void func_0020F030(void *pg, int n);
void func_00213B00(struct O *po, int n);
static __inline__ void VCall50(struct O *po)
{
    struct VTE *e = &po->vt[50];
    ((void (*)(void *))e->pfn)((char *)po + e->d);
}
static __inline__ void VCall49(struct O *po, int n)
{
    struct VTE *e = &po->vt[49];
    ((void (*)(void *, int))e->pfn)((char *)po + e->d, n);
}
void func_00163170(struct X *p, int n)
{
    int i;
    if (p->fC4 == n) return;
    if (p->fC4 == 0) {
        int v;
        p->fC0 = 0;
        for (i = 0; i < p->f68->cA0; i++) {
            struct X *px = p->f68->aA4[i];
            if (px->fC4) {
                p->fC0 = px;
                break;
            }
        }
        if (p->fC0) {
            int j;
            for (j = 0; j < p->fC0->c94; j++) {
                struct X *px = p->fC0->a98[j];
                if (px != p->f68 && !func_00164030(px)) {
                    p->fC0 = 0;
                    break;
                }
            }
        }
        func_001A6CA8(p, 1);
        v = p->fl;
        if ((v ^ 1) & 1)
            *(int *)v |= 0x102;
        else
            p->fl = v | 0x102;
        func_0020EFC0(g_sw, 2);
    }
    p->fC4 = n;
    p->fC8 = g_clock.t;
    switch (n) {
    case 0: {
        int v;
        if (p->pBC) VCall50(p->pBC);
        if (p->pB8) VCall50(p->pB8);
        func_001A6CA8(p, 2);
        v = p->fl;
        if ((v ^ 1) & 1)
            *(int *)v &= ~0x102;
        else
            p->fl = v & ~0x102;
        func_0020F030(g_sw, 2);
        break;
    }
    case 1:
        VCall49(p->pB8, -1);
        func_00213B00(p->pB8, p->fB0);
        break;
    case 3:
        VCall49(p->pBC, -1);
        break;
    case 2:
        func_00213B00(p->pB8, p->fB4);
        break;
    }
}
