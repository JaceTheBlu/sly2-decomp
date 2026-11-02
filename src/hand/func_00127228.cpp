#include "cref.h"
typedef struct Q { char pad[0x10]; struct Q *pnext; } Q;
typedef struct R { char pad[0x10]; Q *pq; } R;
typedef struct P { char pad[0xC]; R *pr; } P;
extern "C" {
CRef func_00127838(Q *pq, CRef *aref);
CRef func_00127228(P *p, CRef *aref);
}
CRef func_00127228(P *p, CRef *aref)
{
    CRef ref;
    Q *pq;
    ref.Decref();
    ref.InitTag(0x24);
    for (pq = p->pr->pq; pq; pq = pq->pnext)
        ref = func_00127838(pq, aref);
    return ref;
}
