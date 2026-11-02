#include "cref.h"
typedef int qword __attribute__((mode(TI)));
struct OBJ { int a[4]; OBJ(); ~OBJ(); };
extern char g_sw[];
extern "C" {
void func_0020FAA0(void *pg, qword a, qword b, void *p3, void *p4, int *pc, void **pap);
void func_0020FDC8(int c, void *ap, int *pc, void **pap);
CRef func_00124078(int c, void *ap);
CRef func_001247D8(void *pbasic, CRef *aref);
}
CRef func_001247D8(void *pbasic, CRef *aref)
{
    CRef ref;
    OBJ obj;
    int c0;
    void *ap0;
    int c1;
    void *ap1;
    func_0020FAA0(g_sw, *(qword *)aref[0].m_p, *(qword *)aref[1].m_p, 0, 0, &c0, &ap0);
    func_0020FDC8(c0, ap0, &c1, &ap1);
    ref = func_00124078(c1, ap1);
    return ref;
}
