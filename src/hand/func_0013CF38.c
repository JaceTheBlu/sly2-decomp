struct A { char pad[0x15c]; void *f15c; };
struct G { char pad[0x4638]; void *f4638; };
extern struct G g_sw;
struct S { char pad[0x194]; struct A *pa; };
int func_0013D248(struct S *);
struct A *func_001CB250(void *, int);
void func_0013C490(struct A *, int);
void func_0013C560(struct A *, int);
void func_0013CF38(struct S *p) {
    struct G *pg;
    int i;
    struct A *pa;
    if (p->pa) return;
    pg = &g_sw;
    if (!pg->f4638) return;
    i = func_0013D248(p);
    if (i == -1) return;
    pa = func_001CB250(pg->f4638, 0);
    p->pa = pa;
    if (pa) {
        func_0013C490(pa, i);
        p->pa->f15c = p;
        func_0013C560(p->pa, 1);
    }
}
