#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *SetBifk__4CRef4BIFK(CRef *pref, int n)
{
    Decref__4CRef(pref);
    pref->m_tag = n;
    pref->m_tagk = 0x19;
    return pref;
}
