struct O { char pad[0x6C]; int n; };
struct E { struct O *po; int a, b; };
struct G2 { char pad[0x48]; int c; struct E ae[1]; };
extern struct G2 D_003DA3C0;
extern struct G g_sw;
void *func_0013E368(struct G *g, int n);
void func_0021ED58(void *p, void *q);
void func_001DDEA0(void *p, int i) {
    struct G2 *pg = &D_003DA3C0;
    if (i < pg->c) func_0021ED58(p, func_0013E368(&g_sw, pg->ae[i].po->n));
}
