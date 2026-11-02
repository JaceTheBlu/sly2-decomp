#include "cref.h"
struct G { char pad[0xFD50]; int xFD50; int xFD54; int xFD58; };
struct H { char pad[0x4C]; int x4C; };
extern struct G D_002E65E0;
extern struct H D_002E6550;
extern int D_003E0FE4;
extern char D_003D4A60[];
void func_002581C0(struct CRef *ret, int a, void *b);
void func_00129EC8(struct CRef *);
void func_001ACB58(struct H *h, int n);
void func_001ABD40(struct G *g);
void func_001AD3E0(void)
{
    struct G *g = &D_002E65E0;
    struct H *h = &D_002E6550;
    struct CRef ref;
    int t;
    g->xFD50 = g->xFD58;
    h->x4C = 2;
    func_002581C0(&ref, D_003E0FE4, D_003D4A60);
    t = ref.m_tag;
    func_00129EC8(&ref);
    if (!t) {
        func_001ACB58(h, 0x22);
    } else {
        func_001ACB58(h, 0x1A);
        func_001ABD40(g);
    }
}
