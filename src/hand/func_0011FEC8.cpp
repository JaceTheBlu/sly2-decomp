#include "cref.h"
#include "vec.h"
// `/` script builtin. The int-matrix path builds its VU_FLOAT temp in the caller, before the inline scale
// helper frame, so the temp reuses the freed CRef slot at sp+0x10 as in the original.
typedef int qword __attribute__((mode(TI)));
struct MATRIX4 { float af[16]; } __attribute__((aligned(16)));
struct V8 { float x, y; };
struct VU_FLOAT {
    qword q;
    VU_FLOAT(float f) { __asm__("mfc1 %0, %1" : "=r"(q) : "f"(f)); }
    float F() const { float g; __asm__("mtc1 %1, %0" : "=f"(g) : "r"(q)); return g; }
};
struct VU_FLOAT_X { qword q; VU_FLOAT_X(float f); };
struct VU_VECTOR { qword q; VU_VECTOR(const VECTOR &v); };
qword operator*(VU_FLOAT_X f, VU_VECTOR v);
extern "C" qword *__as__6VECTORG9VU_VECTOR(VECTOR *p, qword v);
struct NODE { int x0, x4; CRef ref; NODE *pnext; };
CRef func_00129BC8(CRef *pref, void *a, void *b);
extern "C" CRef func_0011FEC8(void *pv, CRef *aref);

struct VU_FLOAT_V {
    qword q;
    VU_FLOAT_V(float f) { __asm__("qmtc2.ni %1, %0" : "=j"(q) : "r"(f)); }
};
static inline void DivVector(qword *pq, float d)
{
    VU_FLOAT_V s(1.0f / d);
    qword a = *pq, r;
    __asm__("vmulx.xyzw %0, %2, %1x" : "=j"(r) : "j"(s.q), "j"(a));
    *pq = r;
}

static inline void ScaleM(MATRIX4 *pm, float g)
{
    MATRIX4 mat;
    for (int i = 0; i < 16; i++)
        mat.af[i] = g * pm->af[i];
    *pm = mat;
}
static inline void DivMatrix(MATRIX4 *pm, float d)
{
    MATRIX4 mat;
    float g = VU_FLOAT(1.0f / d).F();
    for (int i = 0; i < 16; i++)
        mat.af[i] = g * pm->af[i];
    *pm = mat;
}

CRef func_0011FEC8(void *pv, CRef *aref)
{
    CRef ref;
    int fInt = 0;
    switch (aref[0].m_tagk) {
    case 0x15:
        ref = (float)aref[0].m_tag;
        fInt = 1;
        break;
    case 0x16:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
        ref = func_00129BC8(&aref[0], 0, 0);
        break;
    }
    NODE *pn = 0;
    if (aref[1].m_tagk)
        pn = (NODE *)aref[1].m_p;
    for (; pn; pn = pn->pnext) {
        CRef *pr = &pn->ref;
        switch (ref.m_tagk) {
        case 0x16: {
            float d;
            switch (pr->m_tagk) {
            case 0x16:
                d = pr->m_g;
                fInt = 0;
                break;
            case 0x15:
                d = (float)pr->m_tag;
                break;
            default:
                continue;
            }
            ref.m_g /= d;
            break;
        }
        case 0x1A:
            switch (pr->m_tagk) {
            case 0x15: DivVector((qword *)ref.m_p, (float)pr->m_tag); break;
            case 0x16: DivVector((qword *)ref.m_p, pr->m_g); break;
            }
            break;
        case 0x1B:
            switch (pr->m_tagk) {
            case 0x15: ScaleM((MATRIX4 *)ref.m_p, VU_FLOAT(1.0f / (float)pr->m_tag).F()); break;
            case 0x16: DivMatrix((MATRIX4 *)ref.m_p, pr->m_g); break;
            }
            break;
        case 0x1C:
            switch (pr->m_tagk) {
            case 0x15: {
                VECTOR *pvec = (VECTOR *)ref.m_p;
                __as__6VECTORG9VU_VECTOR(pvec, VU_FLOAT_X(1.0f / (float)pr->m_tag) * VU_VECTOR(*pvec));
                break;
            }
            case 0x16: {
                VECTOR *pvec = (VECTOR *)ref.m_p;
                __as__6VECTORG9VU_VECTOR(pvec, VU_FLOAT_X(1.0f / pr->m_g) * VU_VECTOR(*pvec));
                break;
            }
            }
            break;
        case 0x1D: {
            float d;
            switch (pr->m_tagk) {
            case 0x15: d = (float)pr->m_tag; break;
            case 0x16: d = pr->m_g; break;
            default: continue;
            }
            float s = 1.0f / d;
            V8 *p = (V8 *)ref.m_p;
            p->x *= s;
            p->y *= s;
            break;
        }
        }
    }
    if (fInt && ref.m_tagk == 0x16)
        ref = (int)ref.m_g;
    return ref;
}
