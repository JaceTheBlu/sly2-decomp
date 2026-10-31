struct CTX { int a[4]; CTX(); ~CTX(); };
struct AREQ { int cb; int align; AREQ(int c, int a) { cb = c; align = a; } };
struct I { int a; void *b; };
struct E { int id; int n; int c; I *a; };
struct P {
    char pad[0x150];
    int c150;
    void *x154;
    int pad158;
    int i;
    int c;
    E *ae;
};
extern "C" {
void *PvAllocStackImpl__FP7SWALLOC(const AREQ &r);
void *PvAllocStackClearImpl__FP7SWALLOC(const AREQ &r);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(const AREQ &r, void *pv);
}
static inline void *Alloc(int cb) { return PvAllocStackImpl__FP7SWALLOC(AREQ(cb, 0x10)); }
static inline void *AllocB(int cb) { return PvAllocStackClearImpl__FP7SWALLOC(AREQ(cb, 0x10)); }
static inline void *Realloc(void *pv, int cb) { return PvAllocSwCopyImpl__FP7SWALLOCPv(AREQ(cb, 0x10), pv); }
extern "C" {
void func_001F31E0(P *p, void *a);
}

extern "C" void func_001BABA0(P *p, void *a)
{
    CTX ctx;
    int i, j;

    p->x154 = Alloc(0x40);
    p->ae = (E *)AllocB(0x200) + 1;
    func_001F31E0(p, a);
    p->i = 0;
    p->x154 = Realloc(p->x154, p->c150 << 3);
    if (p->c) {
        p->ae = (E *)Realloc(p->ae - 1, (p->c << 4) + 0x10) + 1;
        for (i = -1; i < p->c; i++) {
            E *pe = &p->ae[i];
            pe->a = (I *)Realloc(pe->a, pe->c << 3);
            for (j = 0; j < pe->c; j++) {
                I *pi = &pe->a[j];
                if (pi->a == 0xC) {
                    pi->b = Realloc(pi->b, 8);
                }
            }
        }
    } else {
        p->ae = 0;
    }
}
