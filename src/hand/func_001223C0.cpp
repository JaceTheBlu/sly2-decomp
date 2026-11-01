#include "cref.h"
extern "C" {
CRef func_00129DA8(CRef *pref);
int func_0011D3F8(int a, int b);
float GRandInRange__Fff(float a, float b);
CRef func_001223C0(void *pbasic, CRef *aref);
}
CRef func_001223C0(void *pbasic, CRef *aref)
{
    CRef ref;
    if (aref[0].m_tagk == 0x15 && aref[1].m_tagk == aref[0].m_tagk) {
        ref = func_0011D3F8(aref[0].m_tag, aref[1].m_tag);
    } else {
        float g0 = func_00129DA8(&aref[0]).m_g;
        float g1 = func_00129DA8(&aref[1]).m_g;
        ref = GRandInRange__Fff(g0, g1);
    }
    return ref;
}
