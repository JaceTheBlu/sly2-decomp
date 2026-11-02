#include "cref.h"
struct S { char p0[0x220]; int a220; int a224; };
void func_002013D8(CRef *pref, void *pv, int a, int b, int *pa, int *pb);
void func_00129EC8(CRef *pref);
void func_001D77D0(struct S *p, int n);
void func_001D7780(struct S *p, void *pv) {
    CRef ref;
    func_002013D8(&ref, pv, 6, 6, &p->a220, &p->a224);
    func_00129EC8(&ref);
    func_001D77D0(p, 0);
}
