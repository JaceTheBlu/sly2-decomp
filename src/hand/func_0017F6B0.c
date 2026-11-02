struct K { short x; short y; int i; };
extern struct K D_002A5638;
extern char g_sw[];
struct S { char pad[0x180]; int n180; int n184; int pad2; int n18C; };
void func_00149B58(void *g, int a, void *p, struct K k, int n);
void func_0017F6B0(struct S *p) { p->n184 = p->n180; if (p->n18C) func_00149B58(g_sw, 1, p, D_002A5638, 0); }
