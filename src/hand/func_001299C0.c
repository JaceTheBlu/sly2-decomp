#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *func_001299C0(CRef *pref, int *p)
{
    (*p)++;
    Decref__4CRef(pref);
    pref->m_tag = (int)p;
    pref->m_tagk = 0x20;
    return pref;
}
