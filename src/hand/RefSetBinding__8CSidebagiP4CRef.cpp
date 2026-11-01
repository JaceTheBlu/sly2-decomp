#include "cref.h"
struct BINDING { int a, b; int sym; CRef ref; BINDING *pnext; };
class CSidebag {
public:
    int a, b;
    BINDING *pbindingFirst;
    CRef RefSetBinding(int sym, CRef *pref);
};
CRef CSidebag::RefSetBinding(int sym, CRef *pref)
{
    BINDING *pb;
    for (pb = pbindingFirst; pb; pb = pb->pnext) {
        if (pb->sym == sym) {
            CRef ref;
            pb->ref = *pref;
            ref.Decref();
            ref.InitTag(0x24);
            return ref;
        }
    }
    {
        CRef ref;
        ref.Decref();
        ref.InitTag(0x24);
        return ref;
    }
}
