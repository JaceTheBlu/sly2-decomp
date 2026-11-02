#include "cref.h"
struct B { char data[0x5464]; };
struct G { char pad[0x24]; struct B a[3]; char pad2[0xFD58 - 0x24 - 3 * 0x5464]; struct B *xFD58; };
struct H { char pad[0x4C]; int x4C; };
struct S { int x0, x4, x8; char pad[0x10]; int x1C; };
extern struct G D_002E65E0;
extern struct H D_002E6550;
extern int D_003E0FAC;
void func_002581C0(struct CRef *ret, int a, void *b);
void func_00129EC8(struct CRef *);
void func_001ACB58(struct H *h, int n);
void func_001AD3E0(void);
void func_001AD480(struct S *s)
{
    struct CRef ref;
    struct B *p = &D_002E65E0.a[s->x8];
    float f;
    func_002581C0(&ref, D_003E0FAC, p);
    f = ref.m_g;
    func_00129EC8(&ref);
    D_002E65E0.xFD58 = p;
    if (f == 0.0f)
        func_001AD3E0();
    else
        func_001ACB58(&D_002E6550, 0x1C);
    if (s)
        s->x1C |= 2;
}
