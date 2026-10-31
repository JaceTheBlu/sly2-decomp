#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *__4CRefRC4CRef(CRef *pref, CRef *prefSrc);
void __as__4CRefb(CRef *pref, int f);
int func_001DAEA8(int n);
CRef *func_001256E0(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    ref.m_tagk = -1;
    __as__4CRefb(&ref, func_001DAEA8(aref->m_tag) != 0);
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
