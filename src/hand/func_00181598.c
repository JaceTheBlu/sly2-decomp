struct S { char pad[0x200]; int a; int b; };
extern char g_sw[];
void func_0017F6B0(struct S *p);
void func_001815E8(struct S *p, int n);
void func_0020FF70(void *g, int a, int *pb, struct S *p, int n);
void func_00181598(struct S *p)
{
    func_0017F6B0(p);
    func_001815E8(p, 0);
    func_0020FF70(g_sw, p->a, &p->b, p, 0);
}
