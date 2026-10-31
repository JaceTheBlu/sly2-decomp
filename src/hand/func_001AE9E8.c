struct G;
extern struct G g_sw;
extern char D_002DDED0[], D_002DEB30[];
void func_001D98B0(void);
void SetClockRate__FP5CLOCK3CRKf(void *p, int n, float g);
void func_0020EFC0(struct G *p, int n);
void func_001619A0(void *p, int n, int m);
void func_001AE9E8(void)
{
    func_001D98B0();
    SetClockRate__FP5CLOCK3CRKf(D_002DDED0, 0, 0.0f);
    func_0020EFC0(&g_sw, 0);
    func_001619A0(D_002DEB30, 0x28, 0);
}
