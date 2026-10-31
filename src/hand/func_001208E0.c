#include "cref.h"
CRef *func_001208E0(CRef *ret, void *pbasic, CRef *pref)
{
    int tagk = pref->m_tagk;
    ret->m_tagk = 0x17;
    ret->m_tag = tagk == 0x1B;
    return ret;
}
