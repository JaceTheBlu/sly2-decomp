extern char g_sw[];
extern char g_sndmgr[];
void func_001FE9F8(void *p, float f);
void func_0022B490(void *a, void *b, int c, int d, void *e, int f);
void func_0014C140(void *p)
{
    func_001FE9F8(g_sndmgr, 0.0f);
    func_0022B490(g_sw, 0, 0x189, -1, p, -1);
}
