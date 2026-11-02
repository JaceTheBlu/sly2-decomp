#include "cref.h"
CRef *__4CRefP4NODE(CRef *ret, int *p)
{
    ret->m_tag = (int)p;
    ret->m_tagk = 0x1F;
    (*p)++;
    return ret;
}
