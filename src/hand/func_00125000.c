#include "cref.h"
typedef int TI __attribute__((mode(TI)));
void Decref__4CRef(CRef *pref);
CRef *__4CRefRC4CRef(CRef *pref, CRef *prefSrc);
void InitTag__4CRef(CRef *pref, int tagk);
void func_00129248(CRef *pref, TI vec);
TI func_001A6F00(int a, int b, TI v);
CRef *func_00125000(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    func_00129248(&ref, func_001A6F00(aref[0].m_tag, aref[1].m_tag, *(TI *)aref[2].m_tag));
    __4CRefRC4CRef(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
