struct VTE { short d; short pad; void (*pfn)(); };
struct O { int x0, x4, x8; struct VTE *vt; char pad[0x13C - 0x10]; int k; };
struct PR { int a, b; };
struct S { int x0, x4, x8; struct VTE *vt; char pad[0xE0 - 0x10]; int xE0; char aE4[0x40]; int x124; char a128[0x20]; int c; struct PR apr[1]; };
struct G;
extern struct G g_sw;
extern char D_002DEB30[];
extern char g_cm[];
struct O *PloFindSwObject__FP2SWi3OIDP2LO(struct G *pg, int k, int id, struct S *p);
void func_0020FF70(struct G *pg, int a, void *b, struct S *p, int c);
void func_00161F48(void *a, int b, void *c, struct S *p);
int func_0015E9C8(struct G *pg, int a, int b, int c, int n, struct O **apo);
void func_00228358(struct O *po, int k);
void func_0014D8C0(void *p);
void func_00228750(struct S *p)
{
    struct O *apo[32];
    int i, j;
    for (i = 0; i < p->c; i++) {
        struct PR *ppr = &p->apr[i];
        struct O *po = PloFindSwObject__FP2SWi3OIDP2LO(&g_sw, 4, ppr->a, p);
        if (po) {
            struct O *po2 = PloFindSwObject__FP2SWi3OIDP2LO(&g_sw, 4, ppr->b, p);
            if (po2) po->vt[38].pfn((char *)po + po->vt[38].d, po2);
        }
    }
    func_0020FF70(&g_sw, p->xE0, p->aE4, p, 1);
    func_00161F48(D_002DEB30, p->x124, p->a128, p);
    for (j = func_0015E9C8(&g_sw, 5, 0x1A, 0, 0x20, apo) - 1; j >= 0; j--) {
        if (apo[j]->k != 2) func_00228358(apo[j], 0);
    }
    func_0014D8C0(g_cm);
    p->vt[3].pfn((char *)p + p->vt[3].d, 5, 0, 0, 0, 0);
}
