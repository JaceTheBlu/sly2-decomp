extern char g_sw[];
struct S { char pad[0x14]; void *pv; };
int func_0011A380(void *, void *);
void func_0011A2E8(void *, void *);
void func_00147E20(void *, void *);
void func_0011CD98(void *, void *);
void func_001A53E0(struct S *p)
{
    char *pdl = g_sw + 0x2C;
    if (func_0011A380(pdl, p->pv))
        func_0011A2E8(pdl, p->pv);
    func_00147E20(g_sw, p->pv);
    func_0011CD98(g_sw + 0x398C, p->pv);
    p->pv = 0;
}
