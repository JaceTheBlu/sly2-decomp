#include "cref.h"
typedef int qword __attribute__((mode(TI)));
CRef *func_00129248(CRef *pref, qword v);
CRef *func_001291A8(CRef *pref, CRef *prefSrc);
void func_00129EC8(CRef *pref);
CRef *func_00122770(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    register qword a __asm__("vf1") = *(qword *)aref[0].m_tag;
    register qword b __asm__("vf2") = *(qword *)aref[1].m_tag;
    register qword v __asm__("vf3");
    __asm__ ("vopmula.xyz ACC, %1, %2\n"
        "vopmsub.xyz %0, %2, %1" : "=j"(v) : "j"(a), "j"(b));
    func_00129248(&ref, v);
    func_001291A8(ret, &ref);
    func_00129EC8(&ref);
    return ret;
}
