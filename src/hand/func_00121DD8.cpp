#include "cref.h"
#include "vec.h"
struct NODE { int cref; int x4; CRef ref; NODE *pnext; };
extern "C" {
CRef func_00129DA8(CRef *pref);
CRef func_00121DD8(int c, CRef *pref);
}
CRef func_00121DD8(int c, CRef *pref)
{
    CRef ref(0x1A);
    VECTOR *pv = (VECTOR *)ref.m_p;
    NODE *pn;
    if (c > 0)
        pn = (NODE *)pref->m_p;
    switch (c) {
    case 0:
        pv->z = 0.0f;
        pv->y = 0.0f;
        pv->x = 0.0f;
        break;
    case 1: {
        CRef r = func_00129DA8(&pn->ref);
        float g = r.m_g;
        pv->z = g;
        pv->y = g;
        pv->x = g;
        break;
    }
    case 3: {
        float *pg = &pv->x;
        int i;
        for (i = 0; i < 3; i++) {
            CRef r = func_00129DA8(&pn->ref);
            *pg = r.m_g;
            pg++;
            pn = pn->pnext;
        }
        break;
    }
    }
    return ref;
}
