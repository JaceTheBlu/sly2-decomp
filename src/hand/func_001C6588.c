#include "clock.h"
struct VTE { short d; short pad; void (*pfn)(void *, int); };
struct O { int a[3]; struct VTE *vt; char pad[0x140]; int n150; char pad2[0xE4]; float g238; };
extern struct CLOCK g_clock;
void func_001C5E48(struct O *p);
void func_001C6588(struct O *p)
{
    func_001C5E48(p);
    if (!p->n150) {
        p->g238 -= g_clock.dt;
        if (p->g238 <= 0.0f) { struct VTE *e = &p->vt[76]; e->pfn((char *)p + e->d, 5); }
    }
}
