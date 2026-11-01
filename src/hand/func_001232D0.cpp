#include "cref.h"
typedef int qword __attribute__((mode(TI)));
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct MATRIX3 { VECTOR mat[3]; };
struct MATRIX4 { VECTOR mat[3]; VECTOR pos; };
struct XF { char pad[0x30]; qword pos; };
extern "C" {
void func_0011B938(XF *pxf, int f, MATRIX3 *pmat);
VECTOR *__as__6VECTORG9VU_VECTOR(VECTOR *pv, qword q);
CRef func_001232D0(void *pbasic, CRef *aref);
}
CRef func_001232D0(void *pbasic, CRef *aref)
{
    MATRIX3 mat;
    func_0011B938((XF *)aref[0].m_p, 0, &mat);
    CRef ref(0x1B);
    MATRIX4 *pmat = (MATRIX4 *)ref.m_p;
    __as__6VECTORG9VU_VECTOR(&pmat->pos, ((XF *)aref[0].m_p)->pos);
    *(MATRIX3 *)pmat = mat;
    pmat->mat[2].w = 0.0f;
    pmat->mat[1].w = 0.0f;
    pmat->mat[0].w = 0.0f;
    pmat->pos.w = 1.0f;
    return ref;
}
