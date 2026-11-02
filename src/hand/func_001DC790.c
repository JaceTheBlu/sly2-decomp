struct E { int n; int a; };
struct G2 { char pad[0x4C]; struct E ae[0x40]; int nPad; int i; };
extern struct G2 D_003DA150;
struct T { int a[5]; int id; int b[2]; };
extern struct T D_002BCD00[];
extern struct G g_sw;
void *func_0013E368(struct G *g, int n);
void func_0021ED58(char *p, void *q);
void func_001DC790(char *pch, int i) {
    struct G2 *pg = &D_003DA150;
    unsigned int n = pg->ae[pg->i + i].n;
    int id = -1;
    if (n < 0x2B) id = D_002BCD00[n].id;
    if (id != -1) func_0021ED58(pch, func_0013E368(&g_sw, id));
    else *pch = 0;
}
