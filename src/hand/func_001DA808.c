extern struct CLOCK { float a[16]; } g_clock;
struct S { char p0[0x34]; float g34; };
void func_001D9870(struct S *p);
void func_001DA950(struct S *p, int a, int b);
void func_001DA808(struct S *p) {
    func_001D9870(p);
    if (p->g34 <= g_clock.a[15]) func_001DA950(p, -1, -1);
}
