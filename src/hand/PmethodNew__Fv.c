typedef struct POOL { int x0, x4, x8; void *xC; } POOL;
typedef struct N { int x0; int x4; int x8; int xC; int x10; } N;
extern POOL D_00452170;
extern void *D_00452160[4];
extern int D_003E0EA4;
extern unsigned int D_002DD2D4;
extern int D_002DD598;
void func_001286E0(void *);
void *func_0011CCC0(POOL *);
void FreeSlotheapPv__FP8SLOTHEAPPv(POOL *, void *);
N *func_002560C8(N *);

N *PmethodNew__Fv(void)
{
    N *p;
    if (D_00452170.xC == 0) {
        if (!D_003E0EA4 || D_002DD2D4 >= 4)
            func_001286E0(&D_002DD598);
        if (D_00452170.xC == 0) {
            void *pv = func_0011CCC0(&D_00452170);
            if (D_002DD2D4)
                FreeSlotheapPv__FP8SLOTHEAPPv(&D_00452170, pv);
            D_00452160[D_002DD2D4++] = pv;
        }
    }
    p = (N *)func_0011CCC0(&D_00452170);
    func_002560C8(p);
    return p;
}
