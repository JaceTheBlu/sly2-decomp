#include "mat.h"
typedef int qword __attribute__((mode(TI)));
struct S { char pad[0x1C0]; int n1C0; char pad2[0x54]; float g218; int pad3; qword q220; };
extern "C" {
extern qword g_normalZ, D_002A2DD0;
extern char D_002BE800[], D_002BE810[];
MATRIX3 LoadRotateMatrixRad__FfUx(qword q, float g);
void func_001F59A0(S *p, MATRIX3 *pm, void *pv);
void func_001F5E10(S *p, qword a, int b, qword c, void *pv);
void func_0017FB50(S *p);
}
void func_0017FB50(S *p) {
    if (p->n1C0 == 3) return;
    MATRIX3 m; m = LoadRotateMatrixRad__FfUx(g_normalZ, p->g218);
    func_001F59A0(p, &m, D_002BE800);
    func_001F5E10(p, D_002A2DD0, 0, p->q220, D_002BE810);
}
