#include "cref.h"
typedef int qword __attribute__((mode(TI)));
struct OBJ { int a[4]; OBJ(); ~OBJ(); };
extern char g_sw[];
extern "C" {
void func_0020FC60(void *pg, qword a, void *p3, void *p4, float g, int *pc, void **pap);
void func_0020FDC8(int c, void *ap, int *pc, void **pap);
CRef func_00124078(int c, void *ap);
CRef func_001248B0(void *pbasic, CRef *aref);
}
CRef func_001248B0(void *pbasic, CRef *aref)
{
    CRef ref;
    float g;
    if (aref[1].m_tagk == 0x15)
        g = (float)aref[1].m_tag;
    else
        g = aref[1].m_g;
    OBJ obj;
    int c0;
    void *ap0;
    int c1;
    void *ap1;
    func_0020FC60(g_sw, *(qword *)aref[0].m_p, 0, 0, g, &c0, &ap0);
    func_0020FDC8(c0, ap0, &c1, &ap1);
    ref = func_00124078(c1, ap1);
    return ref;
}
