extern char g_cm[];
void func_001C3FF0(void *p, int b);
void func_0014E328(void *g, int a, void *h, void *p, int z);
void func_0014E4C8(void *g, int a, int b, void *h, void *p, int z);
void func_00225AE8(void *p, int b)
{
    func_001C3FF0(p, b);
    if (b) func_0014E328(g_cm, 9, g_cm + 0x5F0, p, 0);
    else func_0014E4C8(g_cm, 0xF, 9, g_cm + 0x5F0, p, 0);
}
