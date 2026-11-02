#include "mat.h"
#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct R { char pad[0x40]; struct MATRIX4 m; };
struct BUF { qword a[4]; };
struct VTE { short d; short pad; struct R *(*pfn)(void *, struct BUF *); };
struct SO { char pad[0xC]; struct VTE *vt; };
struct Y { int x0, x4, k; };
struct E { int x0, x4; struct SO **ppso; int xC; struct Y y; };
void __ml__FRC7MATRIX4T0(struct MATRIX4 *pm, struct MATRIX4 *pa, struct BUF *pb);
qword func_001A72D0(struct MATRIX4 *pm, int z, qword v);
qword func_001A7348(struct MATRIX4 *pm, int z, qword v);
qword func_0022D348(struct R *r, int z, qword v);

void func_0015AD48(struct E *p, qword *pv, qword *pw)
{
    struct Y *py = &p->y;
    struct SO *pso = *p->ppso;
    struct BUF buf;
    struct MATRIX4 m;
    struct R *r;
    if (!pso) return;
    r = pso->vt[32].pfn((char *)pso + pso->vt[32].d, &buf);
    __ml__FRC7MATRIX4T0(&m, &r->m, &buf);
    *pv = func_001A72D0(&m, 0, *pv);
    if (py->k != 3) {
        *pw = func_001A7348(&m, 0, *pw);
        if (py->k != 2)
            *pw = QwAdd(*pw, func_0022D348(r, 0, py->k == 1 ? *pv : r->m.r[3]));
    }
}
