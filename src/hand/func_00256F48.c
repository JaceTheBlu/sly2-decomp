typedef struct POOL { int x0, x4, x8; void *xC; } POOL;
typedef struct N { int x0; int x4; int x8; int xC; int x10; int x14; int x18; char pad[0x40]; } N;
extern POOL D_00452120;
extern void *D_00452110[4];
extern int D_003E0EA4;
extern unsigned int D_002DD2B4;
extern int D_002DD598;
void func_001286E0(void *);
void *func_0011CCC0(POOL *);
void FreeSlotheapPv__FP8SLOTHEAPPv(POOL *, void *);
N *func_00255A58(N *);

N *func_00256F48(void)
{
    N *p;
    if (D_00452120.xC == 0) {
        if (!D_003E0EA4 || D_002DD2B4 >= 4)
            func_001286E0(&D_002DD598);
        if (D_00452120.xC == 0) {
            void *pv = func_0011CCC0(&D_00452120);
            if (D_002DD2B4)
                FreeSlotheapPv__FP8SLOTHEAPPv(&D_00452120, pv);
            D_00452110[D_002DD2B4++] = pv;
        }
    }
    p = (N *)func_0011CCC0(&D_00452120);
    func_00255A58(p);
    p->x8 = 0;
    p->x14 = 0;
    p->x18 = 0;
    return p;
}
