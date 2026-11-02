#include "util.h"
struct S { char pad[0x14]; struct RGBA c1; struct RGBA c0; };
void func_002160D8(struct S *p);
void func_00215D00(struct S *p, struct RGBA *pc)
{
    p->c0 = *pc;
    p->c1 = p->c0;
    func_002160D8(p);
}
