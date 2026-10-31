#include "cref.h"
CRef *func_001236D8(CRef *ret, void *pbasic, CRef *aref)
{
    float g = aref->m_g;
    ret->m_tagk = 0x15;
    *(int *)&ret->m_g = (int)g;
    return ret;
}
