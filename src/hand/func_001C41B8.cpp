#define CREF_PLAIN   /* this source uses CRef as plain data: no constructor/destructor calls */
#include "cref.h"
extern "C" void func_00129EC8(struct CRef *pref);
class OBase { public: int a, b, c; virtual void V1(); virtual void V2(); virtual void Msg(int, void *, int, void **, CRef *); };
extern "C" int func_001C41B8(OBase *p);
int func_001C41B8(OBase *p)
{
    CRef ref;
    int f = 1;
    ref.m_tagk = 0x17;
    ref.m_tag = f;
    p->Msg(0xD, 0, 0, 0, &ref);
    if (ref.m_tagk == 0x17) f = ref.m_tag;
    func_00129EC8(&ref);
    return f;
}
