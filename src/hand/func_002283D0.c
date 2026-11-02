#include "clock.h"
struct S;
struct VTE { short d; short pad; void (*pfn)(); };
struct S { int x0, x4, x8; struct VTE *vt; char pad[0x134 - 0x10]; int x134; int pad1; int k; char pad2[0x158 - 0x140]; float t; int pad3; float dt; int x164; char a168[4]; };
struct G;
extern struct G g_sw;
extern char g_cm[];
extern char D_002DEB30[];
extern struct CLOCK g_clock;
void func_00228358(struct S *p, int k);
struct S *func_002280D0(struct G *pg);
void func_00161F48(void *a, int b, void *c, struct S *p);
void func_0014E4C8(void *a, int b, int c, void *d, int e, int f);
void func_002283D0(struct S *p)
{
    if (p->k != 3) return;
    if (p->x134) {
        struct S *q;
        func_00228358(p, 0);
        q = func_002280D0(&g_sw);
        if (q) func_002283D0(q);
        return;
    }
    func_00161F48(D_002DEB30, p->x164, p->a168, p);
    func_0014E4C8(g_cm, 2, -1, g_cm + 0x450, 0, 0);
    func_0014E4C8(g_cm, 2, -1, g_cm + 0x520, 0, 0);
    func_00228358(p, 4);
    p->t = g_clock.t + p->dt;
    p->vt[3].pfn((char *)p + p->vt[3].d, 5, 0, 0, 0, 0);
}
