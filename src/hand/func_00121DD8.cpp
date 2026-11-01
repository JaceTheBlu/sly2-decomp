#include "vec.h"
struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(int tagk) { InitTag(tagk); }
    CRef(const CRef &r);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
    CRef &operator=(float g);
};
struct NODE { int cref; int x4; CRef ref; NODE *pnext; };
extern "C" {
CRef func_00129DA8(CRef *pref);
CRef func_00121DD8(int c, CRef *pref);
}
CRef func_00121DD8(int c, CRef *pref)
{
    CRef ref(0x1A);
    VECTOR *pv = (VECTOR *)ref.u.pv;
    NODE *pn;
    if (c > 0)
        pn = (NODE *)pref->u.pv;
    switch (c) {
    case 0:
        pv->z = 0.0f;
        pv->y = 0.0f;
        pv->x = 0.0f;
        break;
    case 1: {
        CRef r = func_00129DA8(&pn->ref);
        float g = r.u.g;
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
            *pg = r.u.g;
            pg++;
            pn = pn->pnext;
        }
        break;
    }
    }
    return ref;
}
