struct K { int a, b; };
extern struct K D_002A96F0;
extern char g_sw[];
struct S { char pad[0x13C]; int x; };
void func_001A5E28(struct S *p);
void func_00149A50(void *g, struct S *p, struct K k, int z);
void func_00221388(struct S *p)
{
    func_001A5E28(p);
    if (p->x) func_00149A50(g_sw, p, D_002A96F0, 0);
}
