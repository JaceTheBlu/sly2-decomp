#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *__as__4CReff(CRef *pref, float g)
{
    Decref__4CRef(pref);
    pref->m_g = g;
    pref->m_tagk = 0x16;
    return pref;
}
