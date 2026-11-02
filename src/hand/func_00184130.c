struct VTE { short d; short pad; void (*pfn)(); };
struct S { char pad[0xC]; struct VTE *vt; char p1[0xFC]; int x10c; char p2[4]; void *x114; int x118; int x11c; char p3[0x3C]; int x15c; int x160; };
extern char g_sw[], D_002DEB30[];
void func_0020FF70(void *g, int a, int *pb, struct S *p, int n);
void func_00161F48(void *g, int a, int *pb, struct S *p);
void func_001DFD58(void *p, int n);
void func_00184130(struct S *p, int n)
{
    struct VTE *e;
    p->x10c = n;
    e = &p->vt[4];
    ((void (*)(void *, int, struct S *))e->pfn)((char *)p + e->d, 6, p);
    func_0020FF70(g_sw, p->x118, &p->x11c, p, 1);
    func_00161F48(D_002DEB30, p->x15c, &p->x160, p);
    e = &p->vt[3];
    ((void (*)(void *, int, int, int, int, int))e->pfn)((char *)p + e->d, 5, 0, 0, 0, 0);
    if (p->x114) func_001DFD58(p->x114, n);
}
