struct O;
struct VTE { short d; short pad; void (*pfn)(); };
struct O { int x0, x4, x8; struct VTE *vt; };
struct S { int k; int x4; char a8[0x4C]; struct O *po; };
struct G;
extern struct G g_sw;
void *func_002333B4(void *p, int c, int n);
void func_0020DF80(struct G *pg, void *p);
void func_0022B090(struct S *p, int k)
{
    struct O *po;
    if (p->k == k) return;
    p->k = k;
    switch (k) {
    case 0:
        p->x4 = 0;
        func_002333B4(p->a8, 0, 0x4C);
        po = p->po;
        if (po) po->vt[50].pfn((char *)po + po->vt[50].d);
        break;
    case 1:
        p->po->vt[49].pfn((char *)p->po + p->po->vt[49].d, 0x311);
        break;
    case 2:
        p->po->vt[49].pfn((char *)p->po + p->po->vt[49].d, 0x30F);
        break;
    case 3:
        func_0020DF80(&g_sw, p->a8);
        p->x4 = 0;
        func_002333B4(p->a8, 0, 0x4C);
        break;
    }
}
