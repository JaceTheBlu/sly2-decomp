typedef int qword __attribute__((mode(TI)));
typedef struct MSG { int cb; int nKind; } MSG;
typedef struct MARK { int a[4]; } MARK;
struct S { char pad[0xE4]; int c; int pad1; void *pEC; };
static __inline__ int Min(int a, int b) { return a < b ? a : b; }
int func_00227C90(struct S *p, qword v, float g);
MARK *func_001AE478(MARK *pm);
void _$_18CBinaryInputStream(MARK *pm, int n);
void *PvAllocStackImpl__FP7SWALLOC(MSG *pmsg);
qword func_001A6F00(int a, struct S *p, qword q);
int PruneBsp__FP3BSPT0fUxPiPP3BSP(void *p, int n, qword v, int *pc, void **ppv, float g);
int func_00227D20(struct S *p, qword v, float g)
{
    if (g <= 1.0f) {
        return func_00227C90(p, v, g);
    } else {
        MARK mark;
        int f = 0;
        MSG msg;
        int c;
        void *pv;
        func_001AE478(&mark);
        {
            int cT = p->c;
            MSG *pm = &msg;
            cT = Min(cT, 0x1555);
            c = cT;
            pm->cb = cT * 12;
            pm->nKind = 0x10;
            pv = PvAllocStackImpl__FP7SWALLOC(pm);
        }
        {
            int r = PruneBsp__FP3BSPT0fUxPiPP3BSP(p->pEC, 0x7FFFFFFF, func_001A6F00(0, p, v), &c, &pv, g);
            if (r == 0 || r == 2) f = 1;
        }
        _$_18CBinaryInputStream(&mark, 2);
        return f;
    }
}
