#include "cref.h"
typedef int qword __attribute__((mode(TI)));
CRef *func_00129248(CRef *pref, qword v);
CRef *func_001291A8(CRef *pref, CRef *prefSrc);
void func_00129EC8(CRef *pref);
CRef *func_00122B70(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    register qword a __asm__("vf3") = *(qword *)aref[0].m_tag;
    register qword b __asm__("vf2") = *(qword *)aref[1].m_tag;
    register qword t __asm__("vf1");
    register qword u __asm__("vf4");
    __asm__ ("vmul.xyz %0, %2, %3\n"
        "vaddw.x %1, $vf0, $vf0w\n"
        "vadday.x ACC, %0, %0y\n"
        "vmaddz.x %0, %1, %0z\n"
        "vmulx.xyzw %0, %3, %0x\n"
        "vsub.xyzw %3, %2, %0" : "=&j"(t), "=&j"(u), "+j"(a), "+j"(b));
    func_00129248(&ref, b);
    func_001291A8(ret, &ref);
    func_00129EC8(&ref);
    return ret;
}
