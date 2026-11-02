#include "cref.h"
typedef int qword __attribute__((mode(TI)));
static __inline__ int GLength(qword *pa)
{
    register qword a __asm__("vf1") = *pa;
    register qword t __asm__("vf2");
    int g;
    __asm__ ("vmul.xyz %0, %0, %0\n"
        "vaddw.x %1, $vf0, $vf0w\n"
        "vadday.x ACC, %0, %0y\n"
        "vmaddz.x %0, %1, %0z" : "+j"(a), "=j"(t));
    __asm__ ("vsqrt Q, %0x\n"
        "vwaitq\n"
        "vaddq.x %0, $vf0, Q" : "+j"(a));
    __asm__ ("qmfc2.ni %0, %1" : "=r"(g) : "j"(a));
    return g;
}
CRef *func_001227D0(CRef *ret, void *pbasic, CRef *aref)
{
    int g = GLength((qword *)aref[0].m_tag);
    ret->m_tagk = 0x16;
    *(volatile int *)&ret->m_tag = g;
    return ret;
}
