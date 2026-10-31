#include "clock.h"
typedef int qword __attribute__((mode(TI)));
extern struct CLOCK g_clock;
extern float D_002BE6C0;
struct G { char pad[0x4020]; void *p4020; };
extern struct G g_sw;
struct R { char pad[0x54]; int n54; };
struct T { char pad[0x208]; int n208; };
struct S { char pad[0x10]; struct T *pt; char pad2[0x1C]; int n30; int pad3; float g38; };
void func_001EEF98(struct S *p);
void func_0017A8C8(struct S *p, int n);
qword func_001A62E8(void *p);
struct R *func_00156698(void *p, qword q, struct T *t);
void func_0017A7F8(struct S *p) {
    int s;
    func_001EEF98(p);
    do {
        s = p->n30;
        if (s < 4) { if (s >= 2 && p->pt->n208) func_0017A8C8(p, -1); }
    } while (s != p->n30);
    if (s == 1 || s == 4) {
        if (g_clock.t - p->g38 > D_002BE6C0) {
            struct G *g = &g_sw;
            p->g38 = g_clock.t;
            func_00156698(g->p4020, func_001A62E8(p->pt), p->pt)->n54 = 3;
        }
    }
}
