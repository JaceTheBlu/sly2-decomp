extern struct CLOCK { float a[16]; } g_clock;
extern float D_002A7984, D_002C3254;
struct S { char p0[0x30]; int n30; float g34; int n38; };
void *func_001FBB90(int n);
void func_001FB2F8(void *p, int n);
void func_001DA950(struct S *p, int n, int m) {
    p->n38 = m;
    p->n30 = n;
    switch (n) {
    case -1:
        p->g34 = -10.0f;
        break;
    case 0:
        p->g34 = D_002A7984;
        func_001FB2F8(func_001FBB90(0x29), 0);
        break;
    case 1:
    default:
        p->g34 = g_clock.a[15] + D_002C3254;
        func_001FB2F8(func_001FBB90(0x36), 0);
        break;
    }
}
