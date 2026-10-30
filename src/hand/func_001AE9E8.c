struct G;
extern struct G g_sw;
extern char D_002DDED0[], D_002DEB30[];
void func_001D98B0(void);
void func_0014D1D0(void *p, int n, float g);
void func_0020EFC0(struct G *p, int n);
void func_001619A0(void *p, int n, int m);
void func_001AE9E8(void)
{
    func_001D98B0();
    func_0014D1D0(D_002DDED0, 0, 0.0f);
    func_0020EFC0(&g_sw, 0);
    func_001619A0(D_002DEB30, 0x28, 0);
}
