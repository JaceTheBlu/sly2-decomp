#include "cref.h"
struct NODE { int x0, x4; CRef ref; NODE *pnext; };
struct P { char pad[0xC]; struct { char pad[0x10]; NODE *pargs; } *pv; };
extern "C" {
CRef func_00127838(NODE *p, void *penv);
CRef func_00120548(int carg, CRef *aref, void *penv);
CRef func_00126BA0(P *p, void *penv);
}
CRef func_00126BA0(P *p, void *penv)
{
    CRef ref;
    CRef arefT[2];
    CRef test;
    NODE *pkey;
    NODE *pcl;
    ref.Decref();
    ref.InitTag(0x24);
    pkey = p->pv->pargs;
    arefT[0] = func_00127838(pkey, penv);
    pcl = pkey->pnext;
    while (pcl) {
        NODE *pc = (NODE *)pcl->ref.m_p;
        int f;
        if (pc->ref.m_tagk == 0xB) {
            f = 1;
        } else {
            NODE *pk;
            f = 0;
            pk = (NODE *)pc->ref.m_p;
            while (pk) {
                arefT[1] = pk->ref;
                test = func_00120548(2, arefT, penv);
                if (test.m_tagk == 0x17 && test.m_tag) {
                    f = 1;
                    pk = 0;
                } else {
                    pk = pk->pnext;
                }
            }
        }
        if (f) {
            for (pc = pc->pnext; pc; pc = pc->pnext)
                ref = func_00127838(pc, penv);
            pcl = 0;
        } else {
            pcl = pcl->pnext;
        }
    }
    return ref;
}
