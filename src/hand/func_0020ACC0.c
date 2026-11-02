#include "mat.h"
typedef int qword __attribute__((mode(TI)));
struct A { char pad[0x30]; qword pos; char pad2[0x60]; int nA0; };
struct B { char pad[0x90]; qword v; struct A *pa; };
struct D { char pad[0x20]; qword v; };
struct S { char pad[0xF08]; struct B *pb; struct D *pd; int nF10; char pad2[0xC]; qword vF20; };
qword func_0022FC48(int a, int b, qword v);
void BuildRotateVectorsMatrix__FUxUx(MATRIX3 *pm, qword a, qword b);
qword DecomposeRotateMatrixEuler__FP7MATRIX3(MATRIX3 *pm);
void func_0020ACC0(struct S *p)
{
    MATRIX3 m;
    qword v, d;
    v = func_0022FC48(p->nF10, p->pb->pa->nA0, p->vF20);
    __asm__("vsub.xyzw %0, %1, %2" : "=j"(d) : "j"(v), "j"(p->pb->pa->pos));
    BuildRotateVectorsMatrix__FUxUx(&m, p->pb->v, d);
    { struct D *pd = p->pd; pd->v = DecomposeRotateMatrixEuler__FP7MATRIX3(&m); }
}
