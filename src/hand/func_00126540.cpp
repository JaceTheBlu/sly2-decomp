#include "cref.h"
typedef struct Q { char pad[0xC]; void *pv0C; void *pv10; } Q;
typedef struct R { char pad[0x10]; Q *pq; } R;
typedef struct P { char pad[0xC]; R *pr; } P;
extern "C" {
CRef func_00127838(void *pv, CRef *aref);
CRef RefAddBinding__6CFrameUiP4CRef(CRef *aref, void *pv, CRef *pref);
CRef func_00126540(P *p, CRef *aref);
}
CRef func_00126540(P *p, CRef *aref) { CRef ref; Q *pq = p->pr->pq; ref = func_00127838(pq->pv10, aref); ref = RefAddBinding__6CFrameUiP4CRef(aref, pq->pv0C, &ref); return ref; }
