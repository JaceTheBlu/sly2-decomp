#include "cref.h"
typedef struct LO { char pad[0xC]; struct LO *pc; char pad2[0x2C]; void *pv; } LO;
typedef struct G { char pad[0x3F0C]; void *pv; } G;
extern G g_sw;
void *PloFindSwNearest__FP2SW3OIDP2LO(G *pg, int k, int a, LO *b, void *c);
void __as__4CRefPv(CRef *pref, void *p);
CRef *func_001291A8(CRef *pref, CRef *prefSrc);
void func_00129EC8(CRef *pref);
CRef *func_001244E8(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    LO *b;
    LO *plo;
    void *pv;
    ref.m_tagk = -1;
    b = (LO *)aref[1].m_tag;
    if (aref[2].m_tagk) {
        plo = ((LO *)aref[2].m_tag)->pc;
    } else {
        plo = b;
    }
    {
        G *pg = &g_sw;
        int a = aref[0].m_tag;
        __as__4CRefPv(&ref, PloFindSwNearest__FP2SW3OIDP2LO(pg, 4, a, b, plo ? plo->pv : pg->pv));
    }
    func_001291A8(ret, &ref);
    func_00129EC8(&ref);
    return ret;
}
