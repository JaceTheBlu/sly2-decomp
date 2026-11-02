extern struct CLOCK { float a[16]; } g_clock;
struct P { int a, b; };
struct S { char p0[0x40]; int n40; float g44; int pad; struct P ap[64]; char p1[0x25C-0x24C]; int n25C, n260, n264; };
void func_001DB820(struct S *p) {
    unsigned int i;
    p->n40 = -1;
    p->g44 = g_clock.a[15];
    p->n25C = -1;
    p->n260 = -1;
    p->n264 = -1;
    for (i = 0; i < 64; i++) {
        p->ap[i].a = -1;
        p->ap[i].b = -1;
    }
}
