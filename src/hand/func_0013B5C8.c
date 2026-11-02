struct S { char pad[0x154]; float f154; };
extern float g_clock;
void func_0013B5C8(struct S *p, float f) { p->f154 = (p->f154 < g_clock + f) ? p->f154 : g_clock + f; }
