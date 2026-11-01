#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct E { union { qword q; struct { float x, y, z, r; } s; } u; float x10; long k:4; long m:8; struct S *child; struct S *next; };
struct S { struct E ae[4]; };
extern float D_002A7870;
typedef struct { char pad[0x3E5C]; struct S *ps; } G;
struct S *func_001D6480(G *g);
static inline float Dist(qword a, qword b)
{
    qword d, t, va;
    float f;
    __asm__("qmtc2.ni %1, %0" : "=j"(va) : "r"(a));
    __asm__("vsub.xyzw %0, %1, %2" : "=j"(d) : "j"(va), "j"(b));
    __asm__("vmul.xyz %0, %0, %0\n\tvaddw.x %1, $vf0, $vf0w\n\tvadday.x $ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z\n\tvsqrt $Q, %0x\n\tvwaitq\n\tvaddq.x %0, $vf0, $Q" : "+j"(d), "=&j"(t));
    __asm__("qmfc2.ni %0, %1" : "=r"(f) : "j"(d));
    return f;
}
struct E *func_001D6508(G *g, qword pos, float r, float f, int mask)
{
    struct S *psLevel = g->ps;
    struct S *ps;
    struct S *psChild;
    struct E *peFree;
    float best;
    if (!psLevel)
        return 0;
    for (;;) {
        ps = psLevel;
        best = D_002A7870;
        psChild = 0;
        peFree = 0;
        for (;;) {
            struct S *psNext = ps->ae[3].next;
            unsigned int i;
            for (i = 0; i < 4; i++) {
                struct E *pe = &ps->ae[i];
                int k = pe->k;
                if (k != -1) {
                    if (k == 1) {
                        float dist = Dist(pos, pe->u.q), o;
                        if (dist + r <= pe->u.s.r) {
                            o = pe->x10;
                            if (o == 1e10f || dist + f <= o) {
                                if (!(mask & ~pe->m)) {
                                    float v = pe->u.s.r * GMin(o, 100000.0f) * GMin(o, 100000.0f);
                                    if (v < best) {
                                        best = v;
                                        psChild = pe->child;
                                    }
                                }
                            }
                        }
                    }
                } else if (!peFree) {
                    peFree = pe;
                }
            }
            if (!psNext)
                break;
            ps = psNext;
        }
        if (!psChild) {
            if (!peFree) {
                ps->ae[3].next = func_001D6480(g);
                peFree = ps->ae[3].next->ae;
            }
            peFree->x10 = f;
            peFree->u.q = pos;
            peFree->u.s.r = r;
            peFree->m = mask;
            break;
        }
        psLevel = psChild;
    }
    return peFree;
}
