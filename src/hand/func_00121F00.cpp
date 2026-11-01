#include "mat.h"
typedef int qword __attribute__((mode(TI)));
struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(int tagk) { InitTag(tagk); }
    CRef(const CRef &r);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
};
struct NODE { int x0, x4; CRef ref; NODE *pnext; };
extern "C" {
void *func_002333B4(void *pv, int b, unsigned int cb);
CRef func_00129DA8(CRef *pref);
CRef func_00121F00(int carg, CRef *pref);
}
CRef func_00121F00(int carg, CRef *pref)
{
    CRef ref(0x1B);
    MATRIX4 *pm = (MATRIX4 *)ref.u.pv;
    NODE *pn;
    if (carg > 0)
        pn = (NODE *)pref->u.pv;
    func_002333B4(pm, 0, sizeof(*pm));
    pm->mat[0][0] = pm->mat[1][1] = pm->mat[2][2] = pm->mat[3][3] = 1.0f;
    switch (carg) {
    case 0:
        break;
    case 1:
        pm->mat[0][0] = pm->mat[1][1] = pm->mat[2][2] = func_00129DA8(&pn->ref).u.g;
        break;
    case 3:
    case 4: {
        int i;
        for (i = 0; i < carg; i++) {
            *(qword *)pm->mat[i] = *(qword *)pn->ref.u.pv;
            pn = pn->pnext;
        }
        break;
    }
    case 9:
    case 16: {
        int n = (carg == 9) ? 3 : 4;
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                CRef r = func_00129DA8(&pn->ref);
                pm->mat[i][j] = r.u.g;
                pn = pn->pnext;
            }
        }
        break;
    }
    }
    return ref;
}
