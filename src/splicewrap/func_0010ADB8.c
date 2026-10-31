#include "splicewrap.h"
void __as__4CRefb(void *, s32);                 /* extern */
s32 func_00142530(s32);                             /* extern */

CRef *func_0010ADB8(CRef *ret, void *pbasic, s32 cref, CRef *aref)
{
    CRef ref;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 0, aref, NULL);
    __as__4CRefb(&ref, func_00142530(pbasic) != 0);
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
