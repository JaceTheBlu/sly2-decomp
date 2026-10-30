typedef unsigned long ulong;
struct VTE { short d; short p; void (*pfn)(void *, float); };
struct VT { VTE a[43]; };
struct L { char pad[0xC]; VT *pvt; struct L *parent; int n14; char pad1[0x24 - 0x18]; struct L *next; ulong lo : 60; ulong b60 : 1; ulong hi : 3; float g30, g34, g38; char pad2[0x64 - 0x3C]; struct L *first; char pad3[0x140 - 0x68]; int n140; };
struct G;
extern G g_sw;
extern "C" void func_001D6310(L *);
extern "C" void func_001D6378(L *);
extern "C" void func_00147E88(G *, int);
extern "C" void func_001F3118(L *p, float t)
{
    L *q;
    int unused[4];
    p->g38 = t;
    if (p->n140 != -1) {
        func_001D6310(p);
        func_001D6378(p);
    }
    if (!p->parent) {
        bool f = p->b60;
        if (f) func_00147E88(&g_sw, p->n14);
    }
    for (q = p->first; q; q = q->next) {
        if (t < q->g38) q->pvt->a[42].pfn((char *)q + q->pvt->a[42].d, t);
    }
}
