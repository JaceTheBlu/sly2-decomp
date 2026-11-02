#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
typedef struct MARK { int a[4]; } MARK;
struct X { char pad[0x60]; };
struct B { char pad[0x70]; qword pos; };
struct A { struct B *pb; };
struct S { char pad[0xEC]; void *xEC; };
struct G { char pad[0x402C]; void *x402C; };
struct R { char pad[0x54]; int x54; };
extern struct G g_sw;
extern int D_002C4368[11];
extern float D_002C4338[11];
void func_0020FA10();
MARK *func_001AE478(MARK *pm);
void _$_18CBinaryInputStream(MARK *pm, int n);
void func_0020FC60(struct G *pg, qword pos, void (*pfn)(), void *pv, float r, int *pc, struct A ***papa);
qword func_0011E208(float a, float b, float c);
qword func_0011E9F8(qword v, float r);
void func_00224820(struct S *p, int a, int b, qword pos, qword posT, int c, struct A **apa, int cMax, int *pcx, struct X *ax);
void func_001F7598(struct X *px);
struct R *func_00156698(void *pv, qword pos, struct S *p);
void func_00224BF8(struct S *p, int a, int b, qword pos, float r)
{
    MARK mark;
    struct X ax[0x20];
    int c;
    struct A **apa;
    int cx;
    int i, j, k, m;
    func_001AE478(&mark);
    func_0020FC60(&g_sw, pos, func_0020FA10, p->xEC, r, &c, &apa);
    cx = 0;
    for (i = 0; i < sizeof(D_002C4368) / sizeof(D_002C4368[0]); i++) {
        for (j = 0; j < D_002C4368[i]; j++) {
            qword v = func_0011E208((float)j * 2.0f * 3.1415927f / (float)D_002C4368[i], D_002C4338[i], r);
            func_00224820(p, a, b, pos, QwAdd(pos, v), c, apa, 0x20, &cx, ax);
        }
    }
    for (k = 0; k < c; k++) {
        qword v = func_0011E9F8(QwSub(apa[k]->pb->pos, pos), r);
        func_00224820(p, a, b, pos, QwAdd(pos, v), c, apa, 0x20, &cx, ax);
    }
    for (m = 0; m < cx; m++)
        func_001F7598(&ax[m]);
    func_00156698(g_sw.x402C, pos, p)->x54 = 1;
    _$_18CBinaryInputStream(&mark, 2);
}
