#include "cref.h"
typedef int qword __attribute__((mode(TI)));
union VQ { struct { float x, y, z, w; } v; qword q; };
struct XFM { char pad[0x80]; qword pos; };
struct O { char pad[0xE8]; XFM *pxfm; };
struct W { char pad[0xC]; O *po; };
extern "C" {
CRef func_00129DA8(CRef *pref);
qword func_001D6848(qword a, qword b, qword c, float g);
CRef func_00122BE0(void *pbasic, CRef *aref);
}
CRef func_00122BE0(void *pbasic, CRef *aref)
{
    VQ v;
    v.v.x = 0.0f;
    v.v.y = 0.0f;
    v.v.z = -1750.0f;
    if (aref[3].m_tagk) {
        O *po = ((W *)aref[3].m_p)->po;
        if (po && po->pxfm)
            v.q = po->pxfm->pos;
    }
    CRef ref(0x1A);
    qword *pq = (qword *)ref.m_p;
    *pq = func_001D6848(*(qword *)aref[0].m_p, *(qword *)aref[1].m_p, v.q, func_00129DA8(&aref[2]).m_g);
    return ref;
}
