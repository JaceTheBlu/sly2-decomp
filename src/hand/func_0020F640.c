extern int D_003E1C54;
extern int D_003E1C30;
struct L { int a[4]; };
struct M { int a; int b; int c[2]; };
void func_00117988(void *q, int n);
void func_001AE478(struct L *pl);
void *PvAllocStackImpl__FP7SWALLOC(struct M *pm);
void Read__18CBinaryInputStreamiPv(void *q, int a, void *x);
void func_001EA568(void *x);
void func_00170730(void *p);
void _$_18CBinaryInputStream(struct L *pl, int n);
void Skip__18CBinaryInputStreami(void *q, int a);
void AddJsgContext__FP3JSG3OID(void *p);
void func_0020F640(void *p, void *q)
{
    func_00117988(q, 0x10);
    if (D_003E1C54) {
        struct L l;
        struct M m;
        void *x;
        func_001AE478(&l);
        { struct M *pm = &m;
        pm->a = D_003E1C30;
        pm->b = 0x10;
        x = PvAllocStackImpl__FP7SWALLOC(pm); }
        Read__18CBinaryInputStreamiPv(q, D_003E1C30, x);
        func_001EA568(x);
        func_00170730(p);
        _$_18CBinaryInputStream(&l, 2);
    } else {
        Skip__18CBinaryInputStreami(q, D_003E1C30);
        AddJsgContext__FP3JSG3OID(p);
    }
}
