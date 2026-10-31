#include "splicewrap.h"
void __as__4CRefb(void *, s32);                 /* extern */
s32 func_00209A68(s32, s32);                        /* extern */

CRef *func_00103AB8(CRef *ret, void *pbasic, s32 cref, CRef *aref)
{
    CRef ref;
    OTYP aotyp[1];
    s32 arg0_v;
    aotyp[0] = 0x1010;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 1, aref, aotyp, &arg0_v);
    __as__4CRefb(&ref, func_00209A68(pbasic, arg0_v) != 0);
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
