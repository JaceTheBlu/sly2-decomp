#include "mat.h"
#include "vec.h"
// script `-` builtin (probably), same shape as func_0011F440: the inline accessor in the
// if/else keeps `pn = 0` after the branch (no jump.c rewrite), so reorg puts it in the beqz delay slot.
typedef int qword __attribute__((mode(TI)));
struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(const CRef &r);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
    CRef &operator=(int n);
    CRef &operator=(float g);
    CRef &operator=(const VECTOR &v);
    CRef &operator=(const MATRIX4 &m);
};
struct NODE { int x0, x4; CRef ref; NODE *pnext; };
extern "C" CRef func_0011F6D0(void *pv, CRef *aref);

static inline NODE *PnFromRef(CRef *p) { return (NODE *)p->u.pv; }
CRef func_0011F6D0(void *pv, CRef *aref)
{
    CRef ref;
    int tagk = aref[0].m_tagk;
    NODE *pn;
    if (aref[1].m_tagk)
        pn = PnFromRef(&aref[1]);
    else
        pn = 0;
    switch (tagk) {
    case 0x15:
    case 0x16: {
        float g;
        int fInt;
        if (tagk == 0x15) {
            g = (float)aref[0].u.n;
            fInt = 1;
        } else {
            g = aref[0].u.g;
            fInt = 0;
        }
        for (; pn; pn = pn->pnext) {
            if (pn->ref.m_tagk == 0x15) {
                g -= (float)pn->ref.u.n;
            } else {
                fInt = 0;
                g -= pn->ref.u.g;
            }
        }
        if (fInt)
            ref = (int)g;
        else
            ref = g;
        break;
    }
    case 0x1A:
        ref = *(VECTOR *)aref[0].u.pv;
        for (; pn; pn = pn->pnext) {
            qword *pq = (qword *)ref.u.pv;
            qword a = *pq, b = *(qword *)pn->ref.u.pv, r;
            __asm__("vsub.xyzw %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
            *pq = r;
        }
        break;
    case 0x1B:
        ref = *(MATRIX4 *)aref[0].u.pv;
        for (; pn; pn = pn->pnext) {
            MATRIX4 *pm = (MATRIX4 *)ref.u.pv;
            MATRIX4 *pmB = (MATRIX4 *)pn->ref.u.pv;
            pm->mat[0][0] -= pmB->mat[0][0]; pm->mat[0][1] -= pmB->mat[0][1]; pm->mat[0][2] -= pmB->mat[0][2]; pm->mat[0][3] -= pmB->mat[0][3];
            pm->mat[1][0] -= pmB->mat[1][0]; pm->mat[1][1] -= pmB->mat[1][1]; pm->mat[1][2] -= pmB->mat[1][2]; pm->mat[1][3] -= pmB->mat[1][3];
            pm->mat[2][0] -= pmB->mat[2][0]; pm->mat[2][1] -= pmB->mat[2][1]; pm->mat[2][2] -= pmB->mat[2][2]; pm->mat[2][3] -= pmB->mat[2][3];
            pm->mat[3][0] -= pmB->mat[3][0]; pm->mat[3][1] -= pmB->mat[3][1]; pm->mat[3][2] -= pmB->mat[3][2]; pm->mat[3][3] -= pmB->mat[3][3];
        }
        break;
    }
    return ref;
}
