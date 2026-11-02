#include "cref.h"
struct OBJ { int a[4]; OBJ(); ~OBJ(); };
struct X { int a[4]; };
extern char D_003E0EA8[];
extern char D_003D4A60[];
extern "C" {
void func_001252D0(void *pv, X *px);
CRef func_001D7ED8(void *a, X *px, void *b);
CRef func_00125398(void *pbasic, CRef *aref);
}
CRef func_00125398(void *pbasic, CRef *aref)
{
    CRef ref;
    OBJ obj;
    X x;
    func_001252D0(aref[0].m_p, &x);
    ref = func_001D7ED8(D_003E0EA8, &x, D_003D4A60);
    return ref;
}
