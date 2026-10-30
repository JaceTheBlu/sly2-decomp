struct G;
extern struct G g_sw;
struct S { char pad[0xFC8]; int n; };
int func_0020F1B8(struct G *p);
int func_00209098(struct S *p) { if (p->n != 0) return 1; return func_0020F1B8(&g_sw); }
