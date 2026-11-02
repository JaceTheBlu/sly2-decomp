extern struct CLOCK { float a[16]; } g_clock;
struct S { char p0[0x40]; int n40; float g44; char p1[0x11C-0x48]; int n11C, n120, n124; };
void func_001DCD08(struct S *p) {
    p->n40 = -1; //P
    p->g44 = g_clock.a[15]; //P
    p->n11C = -1; //P
    p->n120 = -1; //P
    p->n124 = -1; //P
}
