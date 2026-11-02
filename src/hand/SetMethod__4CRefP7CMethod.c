#include "cref.h"
void Decref__4CRef(CRef *pref);
CRef *SetMethod__4CRefP7CMethod(CRef *pref, int *p)
{
    (*p)++;
    Decref__4CRef(pref);
    pref->m_tag = (int)p;
    pref->m_tagk = 0x22;
    return pref;
}
