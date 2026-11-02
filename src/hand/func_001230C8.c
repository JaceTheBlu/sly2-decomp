#include "cref.h"
typedef int TI __attribute__((mode(TI)));
void Decref__4CRef(CRef *pref);
CRef *__4CRefRC4CRef(CRef *pref, CRef *prefSrc);
void func_00129248(CRef *pref, TI vec);
TI DecomposeRotateMatrixEuler__FP7MATRIX3(int n);
CRef *func_001230C8(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    func_00129248(&ref, DecomposeRotateMatrixEuler__FP7MATRIX3(aref->m_tag));
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
