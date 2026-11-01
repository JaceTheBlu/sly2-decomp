#include "cref.h"
struct OBJ { int a[4]; OBJ(); ~OBJ(); };
struct X { int a[4]; };
extern char D_003E0EA8[];
extern char D_003D4A60[];
extern "C" {
void func_001252D0(void *pv, X *px);
CRef func_001D80C8(void *a, X *px, CRef *pref, void *b);
CRef func_00125450(void *pbasic, CRef *aref);
}
CRef func_00125450(void *pbasic, CRef *aref)
{
    CRef ref;
    OBJ obj;
    X x;
    func_001252D0(aref[0].m_p, &x);
    ref = func_001D80C8(D_003E0EA8, &x, &aref[1], D_003D4A60);
    return ref;
}
