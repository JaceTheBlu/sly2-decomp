struct K { int a, b; };
extern struct K D_002A96F0;
extern char g_sw[];
struct S { char pad[0x13C]; int x; };
void UpdateLo(struct S *p);
void func_00149A50(void *g, struct S *p, struct K k, int z);
void UpdateCid15(struct S *p)
{
    UpdateLo(p);
    if (p->x) func_00149A50(g_sw, p, D_002A96F0, 0);
}
