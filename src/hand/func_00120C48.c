#include "cref.h"
void InitTag__4CRef(CRef *pref, int tagk);
void func_00129658(CRef *pref, CRef *prefSrc);
void __as__3SPMP4NODE(void *p, void *q);
CRef *func_00120C48(CRef *ret, void *pbasic, CRef *aref, int cref, int k)
{
    char *p = aref[0].m_p;
    if (k == 0x23)
        func_00129658((CRef *)(p + 8), &aref[1]);
    else if (aref[1].m_tagk == 0x1F)
        __as__3SPMP4NODE(p + 0x10, aref[1].m_p);
    else
        __as__3SPMP4NODE(p + 0x10, 0);
    InitTag__4CRef(ret, 0x24);
    return ret;
}
