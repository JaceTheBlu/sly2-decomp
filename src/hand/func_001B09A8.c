struct G { char pad[0x3B0C]; void *p3b0c; };
extern struct G g_sw;
extern char D_002A3928[];
struct S { char pad[0x1C]; int f; };
void func_0022B490(struct G *pg, void *s, int a, int b, int c, int d);
void func_00162E38(void *p);
void func_001B09A8(struct S *p)
{
    struct G *pg = &g_sw;
    func_0022B490(pg, D_002A3928, 0x189, -1, 0x80, -1);
    if (pg->p3b0c) func_00162E38(pg->p3b0c);
    if (p) p->f |= 2;
}
