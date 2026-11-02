struct VTE { short d; short pad; void (*pfn)(void *, int, int, int, int, int); };
struct S { char pad[0xC]; struct VTE *vt; char p2[0x1F0]; int a; int b; };
extern char g_sw[];
void func_0020FF70(void *g, int a, int *pb, struct S *p, int n);
void func_00181780(struct S *p)
{
    struct VTE *e;
    func_0020FF70(g_sw, p->a, &p->b, p, 1);
    e = &p->vt[3];
    e->pfn((char *)p + e->d, 5, 0, 0, 0, 0);
}
