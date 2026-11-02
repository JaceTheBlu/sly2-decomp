#include "cref.h"
extern char g_sw[];
extern "C" {
int func_0015E9C8(void *pg, int k, void *a, int b, int c, void **ap);
CRef func_00124078(int c, void **ap);
CRef func_00124730(void *pbasic, CRef *aref);
}
CRef func_00124730(void *pbasic, CRef *aref)
{
    CRef ref;
    void *ap[0x180];
    int b = aref[1].m_tag;
    int c = func_0015E9C8(g_sw, b ? 0x401 : 0x405, aref[0].m_p, b, 0x180, ap);
    ref = func_00124078(c, ap);
    return ref;
}
