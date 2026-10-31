typedef struct CLOCK { float t; float dt; } CLOCK;
extern CLOCK g_clock;
struct E { int n; float t; int pad[2]; };
struct S { char pad[0xFC]; int c; int pad100; struct E a[1]; };
void func_00153FF8(struct S *p)
{
    int i;
    for (i = 0; i < p->c; i++) {
        p->a[i].n = 0;
        p->a[i].t = g_clock.t;
    }
}
