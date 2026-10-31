extern struct CLOCK { float t; } g_clock;
struct S { char pad[0x14]; float g14; };
void func_001CF518(struct S *p);
void func_001D00D0(struct S *p) {
    if (g_clock.t < p->g14) return;
    func_001CF518(p);
}
