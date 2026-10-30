typedef unsigned long ulong;
struct T { char pad[0xA4]; int k; };
struct S { char pad[0x10]; int a; int b; char pad2[0x10]; ulong f; char pad3[0x30]; struct T *t; char pad4[0xDC]; int k; };
extern char g_sw[];
void func_001D6310(struct S *p);
void func_001D6378(struct S *p);
void func_00147E88(void *g, int b);
void func_0022FA20(struct S *p)
{
    if (!!((p->f >> 60) & 1)) {
        int k = p->k;
        if (k != -1 && p->t->k != k) { func_001D6310(p); func_001D6378(p); }
        if (p->a == 0) func_00147E88(g_sw, p->b);
    }
}
