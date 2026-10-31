#include "cref.h"
typedef int qword __attribute__((mode(TI)));
typedef struct MATRIX4 { qword a[4]; } MATRIX4;
void SetTag__4CRef4TAGK(CRef *pref, int tagk);
void func_001A71B0(MATRIX4 *pmat, int a, int b, int c);
CRef *func_001291A8(CRef *pref, CRef *prefSrc);
void func_00129EC8(CRef *pref);
CRef *func_001250D8(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    MATRIX4 mat;
    MATRIX4 *pmat;
    SetTag__4CRef4TAGK(&ref, 0x1B);
    pmat = (MATRIX4 *)ref.m_tag;
    func_001A71B0(&mat, aref[0].m_tag, aref[1].m_tag, aref[2].m_tag);
    *pmat = mat;
    func_001291A8(ret, &ref);
    func_00129EC8(&ref);
    return ret;
}
