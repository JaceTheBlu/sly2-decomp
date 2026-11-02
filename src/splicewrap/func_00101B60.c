#include "splicewrap.h"
void __as__4CReff(void *, f32);                 /* extern */
f32 TFindAsegLabel__FP4ASEG3OID(s32, s32);                        /* extern */

CRef *func_00101B60(CRef *ret, void *pbasic, s32 cref, CRef *aref)
{
    CRef ref;
    OTYP aotyp[1];
    s32 arg0_v;
    aotyp[0] = 6;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 1, aref, aotyp, &arg0_v);
    __as__4CReff(&ref, TFindAsegLabel__FP4ASEG3OID(pbasic, arg0_v));
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
