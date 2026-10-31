struct H { int a[4]; };
struct A { int cb; int align; };
struct R { char pad[0x124]; int x124; };
struct Q { char pad[0x124]; struct R *x124; int x128; };
struct B { int c; int *p; };
struct S { char pad[0x10]; int c10; int p14[2]; struct B *x1C; int c20; struct Q **a24; };
int func_001AE478(struct H *p);
void _$_18CBinaryInputStream(struct H *p, int n);
int *PvAllocStackClearImpl__FP7SWALLOC(struct A *pa);
void *PvAllocSwImpl__Fi(struct A *pa);
static inline int *Alloc1(struct A *pa) { pa->align = 0x10; return PvAllocStackClearImpl__FP7SWALLOC(pa); }
static inline void *Alloc2(struct A *pa) { pa->align = 0x10; return PvAllocSwImpl__Fi(pa); }
void func_001C1260(struct S *p)
{
    struct H h;
    struct A a;
    int *ac;
    int i, j, k;
    func_001AE478(&h);
    a.cb = p->c10 * 4;
    ac = Alloc1(&a);
    for (i = 0; i < p->c20; i++) {
        struct Q *q = p->a24[i];
        if (q->x124 && q->x128)
            ac[q->x124->x124]++;
    }
    a.cb = p->c10 * 8;
    p->x1C = Alloc2(&a);
    for (j = 0; j < p->c10; j++) {
        struct B *pb = &p->x1C[j];
        pb->c = 0;
        a.cb = ac[j] * 4;
        pb->p = Alloc2(&a);
    }
    for (k = 0; k < p->c20; k++) {
        struct Q *q = p->a24[k];
        if (q->x124 && q->x128) {
            struct B *pb = &p->x1C[q->x124->x124];
            pb->p[pb->c++] = k;
        }
    }
    _$_18CBinaryInputStream(&h, 2);
}
