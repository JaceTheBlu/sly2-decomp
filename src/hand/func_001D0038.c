struct VTE { short d; short pad; void (*pfn)(); };
struct O { int a, b, c; struct VTE *vt; };
extern struct CLOCK { float t; } g_clock;
struct S { char p0[0x14]; float g14; float g18; struct O *po; char p1[0x104-0x20]; int f104; };
void func_001CFD30(struct S *p);
void func_001CE980(struct S *p);
void func_001D0038(struct S *p) {
    if (g_clock.t >= p->g14 && p->f104) func_001CFD30(p);
    if (g_clock.t - p->g14 > p->g18) {
        struct O *po = p->po;
        struct VTE *e = &po->vt[8];
        ((void (*)(void *))e->pfn)((char *)po + e->d);
        func_001CE980(p);
    }
}
