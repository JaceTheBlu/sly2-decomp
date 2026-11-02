#include "cref.h"
struct Q { char pad[0x3C]; void *pv; };
struct W { char pad[0xC]; Q *pq; };
struct G { char pad[0x3F0C]; void *pv; };
extern G g_sw;
extern "C" {
int CploFindSwObjects__FP2SWi3OIDP2LOP3PXRiPP2LO(G *pg, int k, void *a, Q *b, void *c, int n, void **ap);
CRef func_00124078(int c, void **ap);
CRef func_001241E8(void *pbasic, CRef *aref);
}
CRef func_001241E8(void *pbasic, CRef *aref)
{
    CRef ref;
    void *ap[0x40];
    Q *pq = (Q *)aref[1].m_p;
    Q *pqT;
    if (aref[2].m_tagk)
        pqT = ((W *)aref[2].m_p)->pq;
    else
        pqT = pq;
    G *pg = &g_sw;
    int k = pq ? 1 : 5;
    void *p0 = aref[0].m_p;
    void *pv;
    if (pqT)
        pv = pqT->pv;
    else
        pv = pg->pv;
    int c = CploFindSwObjects__FP2SWi3OIDP2LOP3PXRiPP2LO(pg, k, p0, pq, pv, 0x40, ap);
    ref = func_00124078(c, ap);
    return ref;
}
