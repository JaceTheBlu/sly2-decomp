#include "cref.h"
extern "C" {
CRef func_00129DA8(CRef *pref);
void func_0011D8D8(void *pv, float a, float b, float c, float d);
CRef func_00123498(void *pbasic, CRef *aref);
}
CRef func_00123498(void *pbasic, CRef *aref)
{
    CRef ref(0x1C);
    {
        CRef r0 = func_00129DA8(&aref[0]);
        float g0 = r0.m_g;
        CRef r1 = func_00129DA8(&aref[1]);
        float g1 = r1.m_g;
        CRef r2 = func_00129DA8(&aref[2]);
        float g2 = r2.m_g;
        CRef r3 = func_00129DA8(&aref[3]);
        func_0011D8D8(ref.m_p, g0, g1, g2, r3.m_g);
    }
    return ref;
}
