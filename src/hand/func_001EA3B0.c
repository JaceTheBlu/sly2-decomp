#include "util.h"
struct S { char pad[0xC]; int c; struct LM alm[1]; };
struct LM *func_001EA3B0(struct S *p, float g)
{
    int i;
    struct LM *alm = p->alm;
    for (i = 0; i < p->c; i++) {
        struct LM *plm = &alm[i];
        if (plm->gMin <= g && g <= plm->gMax) return plm;
    }
    return 0;
}
