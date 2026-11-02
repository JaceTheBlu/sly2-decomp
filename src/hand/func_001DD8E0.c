struct S { char p0[8]; void *p8; };
extern char g_sw[];
void func_001A2BD0(void *p);
void func_0022B490(void *g, int a, int b, int c, int d, int e);
void func_001DD8E0(struct S *p) {
    func_001A2BD0(p->p8);
    func_0022B490(g_sw, 0, 0x189, -1, 1, -1);
}
