#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *__as__4CRefP4NODE(CRef *pref, int *p)
{
    (*p)++;
    Decref__4CRef(pref);
    pref->m_tag = (int)p;
    pref->m_tagk = 0x1F;
    return pref;
}
