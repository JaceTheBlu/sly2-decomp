#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *__4CRefRC4CRef(CRef *pref, CRef *prefSrc);
void __as__4CRefPv(CRef *pref, void *p);
extern char g_sw[];
CRef *func_00124640(CRef *ret)
{
    CRef ref;
    ref.m_tagk = -1;
    __as__4CRefPv(&ref, g_sw);
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
