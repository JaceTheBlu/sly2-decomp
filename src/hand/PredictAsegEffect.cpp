#include "mat.h"
// memsets through an inline ClearM4 helper keep &m2/&mB out of gcse; pe at function scope.
typedef int qword __attribute__((mode(TI)));
struct AREQ { int cb; int cbAlign; AREQ(int c, int a) { cb = c; cbAlign = a; } };
class FRAME { public: FRAME(); ~FRAME(); int a[4]; };
struct Y { MATRIX4 m; char pad[0x94 - 0x40]; int x94; int pad98[2]; Y *pyNext; };
struct OBJ { virtual void f1(); virtual void f2(); virtual void Eval(float f, float g, qword *pq1, qword *pq2); };
struct ENT { unsigned n : 20; unsigned k : 10; unsigned f30 : 1; unsigned f31 : 1; OBJ *pobj; };
struct X { char pad[0x5C]; int c; ENT *aent; };
extern "C" {
void *PvAllocStackImpl__FP7SWALLOC(const AREQ &req);
void *func_002333B4(void *pv, int b, int cb);
void func_0012FE58(X *px, void *p, ENT *pent, int *pa, Y **ppy);
MATRIX4 __ml__FRC7MATRIX4T0(MATRIX4 *pa, MATRIX4 *pb);
MATRIX4 func_0022C8C0(Y *py, qword q);
MATRIX4 func_0022CB90(Y *py, MATRIX4 *pm, qword q1, qword q2);
MATRIX4 func_0022CC00(Y *py, qword q);
void PredictAsegEffect(X *px, void *p, Y *pyFirst, Y *pyLast, float f, float g, MATRIX4 *pm1, MATRIX4 *pm2);
}
static inline void ClearM4(MATRIX4 *pm) { func_002333B4(pm, 0, sizeof(MATRIX4)); }
static inline MATRIX4 AddM4(const MATRIX4 &a, const MATRIX4 &b) return m
{
    int i;
    for (i = 0; i < 4; i++) {
        qword q;
        __asm__("vadd.xyzw %0, %1, %2" : "=j"(q) : "j"(a.r[i]), "j"(b.r[i]));
        m.r[i] = q;
    }
}
void PredictAsegEffect(X *px, void *p, Y *pyFirst, Y *pyLast, float f, float g, MATRIX4 *pm1, MATRIX4 *pm2)
{
    MATRIX4 mA;
    MATRIX4 mB;
    MATRIX4 m1;
    MATRIX4 m2;
    FRAME frame;
    qword aq[2];
    Y **apy;
    int i;
    Y *py;
    ENT *pe;
    ClearM4(&m2);
    {
        float *pg = (float *)&m1;
        func_002333B4(pg, 0, sizeof(MATRIX4));
        pg[15] = 1.0f; pg[10] = 1.0f; pg[5] = 1.0f; pg[0] = 1.0f;
    }
    apy = (Y **)PvAllocStackImpl__FP7SWALLOC(AREQ(px->c * 4, 0x10));
    for (i = 0; i < px->c; i++) {
        pe = &px->aent[i];
        if (pe->f30) {
            apy[i] = 0;
        } else {
            int n;
            func_0012FE58(px, p, pe, &n, &apy[i]);
        }
    }
    for (py = pyFirst; py != pyLast; py = py->pyNext) {
        for (i = 0; i < px->c; i++) {
            pe = &px->aent[i];
            if (py == apy[i] && !pe->f31) {
                pe->pobj->Eval(f, g, &aq[0], &aq[1]);
                mA = func_0022C8C0(py, aq[0]);
                switch (py->x94) {
                case 6: case 7:
                    mB = func_0022CB90(py, &mA, aq[0], aq[1]);
                    break;
                default:
                    mB = func_0022CC00(py, aq[1]);
                    break;
                }
                goto found;
            }
        }
        mA = py->m;
        ClearM4(&mB);
    found:
        {
            m2 = AddM4(__ml__FRC7MATRIX4T0(&mA, &m2), __ml__FRC7MATRIX4T0(&mB, &m1));
            m1 = __ml__FRC7MATRIX4T0(&mA, &m1);
        }
    }
    if (pm1) *pm1 = m1;
    if (pm2) *pm2 = m2;
}
