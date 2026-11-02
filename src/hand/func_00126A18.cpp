#include "cref.h"
// func_00126A18: walks a clause list; first clause whose test is not false (tagk 0x17 with value 0) wins
struct NODE { int x0, x4; CRef ref; NODE *pnext; };
struct P { char pad[0xC]; struct { char pad[0x10]; NODE *pcl; } *pv; };
extern "C" {
CRef func_00127838(NODE *p, void *penv);
CRef func_00126A18(P *p, void *penv);
}
CRef func_00126A18(P *p, void *penv)
{
    CRef ref;
    CRef test;
    NODE *pcl;
    ref.Decref();
    ref.InitTag(0x24);
    pcl = p->pv->pcl;
    while (pcl) {
        NODE *pc = (NODE *)pcl->ref.m_p;
        int f;
        if (pc->ref.m_tagk == 0xB) {
            f = 1;
        } else {
            test = func_00127838(pc, penv);
            f = 0;
            if (test.m_tagk != 0x17 || test.m_tag)
                f = 1;
            if (f && !pc->pnext)
                ref = test;
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
