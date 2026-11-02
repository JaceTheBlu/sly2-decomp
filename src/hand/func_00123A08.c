#include "cref.h"
extern float g_clock;
CRef *func_00123A08(CRef *ret)
{
    ret->m_tagk = 0x16;
    ret->m_g = g_clock;
    return ret;
}
