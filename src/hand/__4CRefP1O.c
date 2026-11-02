#include "cref.h"
CRef *__4CRefP1O(CRef *ret, int *p)
{
    ret->m_tag = (int)p;
    ret->m_tagk = 0x20;
    (*p)++;
    return ret;
}
