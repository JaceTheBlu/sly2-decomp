#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *__4CRefRC4CRef(CRef *pref, CRef *prefSrc);
CRef *func_00125C30(CRef *ret)
{
    CRef ref;
    ref.m_tagk = -1;
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
