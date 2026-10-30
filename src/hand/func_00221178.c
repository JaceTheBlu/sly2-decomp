struct S;
struct VTE { short d; short pad; int (*pfn)(); };
struct S { int x0, x4, x8; struct VTE *vt; char pad[0xE0 - 0x10]; void *pE0; char pad1[0x128 - 0xE4]; int x128; char pad2[0x134 - 0x12C]; int k; float t; };
extern char g_cm[];
struct CLOCK { float t; float dt; };
extern struct CLOCK D_002DDED0;
void func_0014E328(void *a, int b, void *c, void *d, struct S *p);
void func_0014E4C8(void *a, int b, int c, int d, int e, struct S *p);
void func_00221178(struct S *p, int k)
{
    if (k == p->k) return;
    switch (k) {
    case 1:
        func_0014E328(g_cm, p->x128 + 2, g_cm + 0x3B0, p->pE0, p);
        p->vt[3].pfn((char *)p + p->vt[3].d, 5, 1, 0, 0, 0);
        break;
    case 0:
        func_0014E4C8(g_cm, 8, -1, 0, 0, p);
        p->vt[3].pfn((char *)p + p->vt[3].d, 6, 1, 0, 0, 0);
        break;
    }
    p->k = k;
    p->t = D_002DDED0.t;
}
