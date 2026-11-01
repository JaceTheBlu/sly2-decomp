#include "cref.h"
struct Q { char pad[0x10]; Q *pnext; };
struct R { char pad[0x10]; Q *pq; };
struct P { char pad[0xC]; R *pr; };
extern "C" {
CRef func_00127838(Q *pq, CRef *aref);
CRef func_00126928(P *p, CRef *aref);
}
CRef func_00126928(P *p, CRef *aref)
{
    CRef ref;
    Q *pq;
    ref = true;
    for (pq = p->pr->pq; pq; pq = pq->pnext) {
        ref = func_00127838(pq, aref);
        if (ref.m_tagk == 0x17 && ref.m_tag == 0)
            return ref;
    }
    return ref;
}
