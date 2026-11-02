#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
static __inline__ qword Make(float x, float y, float z)
{
    qword q, t;
    __asm__("mfc1 %0,%2
	mfc1 %1,%3
	pextlw %0,%1,%0
	mfc1 %1,%4
	pcpyld %0,%1,%0"
            : "=&r"(q), "=&r"(t) : "f"(x), "f"(y), "f"(z));
    return q;
}
qword DecomposeRotateMatrixEuler__FP7MATRIX3(void *p);
qword func_0014F478(char *p)
{
    union { qword q; float f; } r;
    qword v = DecomposeRotateMatrixEuler__FP7MATRIX3(p + 0x60);
    r.q = Make(GetX(v) * 57.295776f, GetY(v) * 57.295776f, GetZ(v) * 57.295776f);
    return r.q;
}
