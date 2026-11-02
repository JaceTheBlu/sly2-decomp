struct VTE { short d; short pad; void (*pfn)(); };
struct O { int a[3]; struct VTE *vt; };
struct B { int pad[3]; int nC; int pad10; struct O *po; };
struct A { int pad[4]; struct B *pb; };
extern char g_cm[];
void func_0014FCE8(struct A *a, int n, struct B *b);
void func_0014D8C0(void *p);
void func_00151698(struct A *a, int n, struct B *b)
{
    struct O *o;
    struct VTE *e;
    func_0014FCE8(a, n, b);
    if (b->nC)
        func_0014D8C0(g_cm);
    o = a->pb->po;
    e = &o->vt[2];
    e->pfn((char *)o + e->d);
    a->pb = 0;
}
