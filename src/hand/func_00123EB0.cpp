#include "cref.h"
extern "C" {
CRef func_00200CA8(void *a, void *b, CRef *pref);
CRef func_00200D10(void *a, void *b, CRef *pref);
CRef func_00200C28(void *a, void *b, CRef *pref);
CRef func_00200BA0(void *a, void *b);
CRef func_00123EB0(void *pbasic, CRef *aref, void *pv, int op);
}
CRef func_00123EB0(void *pbasic, CRef *aref, void *pv, int op)
{
    CRef ref;
    void *a = aref[0].m_p;
    void *b = aref[1].m_p;
    switch (op) {
    case 0x6C:
        ref = func_00200CA8(a, b, &aref[2]);
        break;
    case 0x6D:
        ref = func_00200D10(a, b, &aref[2]);
        break;
    case 0x6E:
        ref = func_00200C28(a, b, &aref[2]);
        break;
    case 0x6F:
        ref = func_00200BA0(a, b);
        break;
    }
    return ref;
}
