struct CLOCK { float t; float dt; };
extern struct CLOCK D_002DDED0;
extern char g_sw[];
struct G { char pad[0x4A4]; int n4A4; };
extern struct G g_cm;
int func_00210AE0(void);
void func_00161868(void *p);
int func_0015E9C8(void *p, int a, int b, int c, int d, int e);
void func_001618B0(void *p);
void *func_001FBB90(int n);
void func_001FB2F8(void *p, int n);
void func_00140338(void)
{
    if (func_00210AE0()) {
        func_00161868(g_sw);
        if (func_0015E9C8(g_sw, 0x605, 0x5F, 0, 0, 0)) func_001618B0(g_sw);
        func_001FB2F8(func_001FBB90(0x32), 0);
        *(float *)(g_sw + 0x4754) = D_002DDED0.t;
        g_cm.n4A4++;
    }
}
