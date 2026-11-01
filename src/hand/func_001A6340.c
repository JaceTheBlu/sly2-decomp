#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
static __inline__ qword Make(float x, float y, float z)
{
    qword q, t;
    __asm__("mfc1 %0,%2\n\tmfc1 %1,%3\n\tpextlw %0,%1,%0\n\tmfc1 %1,%4\n\tpcpyld %0,%1,%0"
            : "=&r"(q), "=&r"(t) : "f"(x), "f"(y), "f"(z));
    return q;
}
extern void *func_001A6318(void);
extern qword DecomposeRotateMatrixEuler__FP7MATRIX3(void *p);
qword func_001A6340(void)
{
    union { qword q; float f; } r;
    qword v = DecomposeRotateMatrixEuler__FP7MATRIX3(func_001A6318());
    r.q = Make(GetX(v) * 57.2957763671875f, GetY(v) * 57.2957763671875f, GetZ(v) * 57.2957763671875f);
    return r.q;
}
