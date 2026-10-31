struct G;
extern struct G g_sw;
extern char g_clock[], D_002DEB30[];
struct S { char pad[0x24]; int x24; };
void func_001D9910(struct S *p);
void SetClockRate__FP5CLOCK3CRKf(void *p, int n, float g);
void func_0020F030(struct G *p, int n);
void func_001619A0(void *p, int n, int m);
void func_001AEA40(struct S *p)
{
    func_001D9910(p);
    p->x24 = 0;
    SetClockRate__FP5CLOCK3CRKf(g_clock, 0, 1.0f);
    func_0020F030(&g_sw, 0);
    func_001619A0(D_002DEB30, 0x2C, 0);
}
