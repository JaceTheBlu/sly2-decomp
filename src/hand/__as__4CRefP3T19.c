#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *__as__4CRefP3T19(CRef *pref, int n)
{
    Decref__4CRef(pref);
    pref->m_tag = n;
    pref->m_tagk = 0x18;
    return pref;
}
