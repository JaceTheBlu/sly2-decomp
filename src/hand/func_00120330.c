#include "cref.h"
void Decref__4CRef(CRef *pref);
void InitTag__4CRef(CRef *pref, int tagk);
CRef *func_00120330(CRef *ret)
{
    CRef ref;
    ref.m_tagk = -1;
    InitTag__4CRef(ret, 0x24);
    Decref__4CRef(&ref);
    return ret;
}
