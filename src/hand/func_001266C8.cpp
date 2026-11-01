#include "cref.h"
struct Q { char pad[0x10]; void *pv; };
struct P { char pad[0xC]; Q *pq; };
extern "C" {
CRef func_00127838(void *pv, CRef *aref);
CRef func_001266C8(P *p, CRef *aref);
}
CRef func_001266C8(P *p, CRef *aref) { CRef ref; void *pv = p->pq->pv; if (pv) { ref = func_00127838(pv, aref); } else { ref.Decref(); ref.InitTag(0x24); } return ref; }
