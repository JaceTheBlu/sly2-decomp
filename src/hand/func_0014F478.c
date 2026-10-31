typedef int qword __attribute__((mode(TI)));
static __inline__ float GetX(qword q) { float x; __asm__("mtc1 %1,%0" : "=f"(x) : "r"(q)); return x; }
static __inline__ float GetY(qword q) { float y; __asm__("prot3w %0,%1" : "=r"(y) : "r"(q)); return y; }
static __inline__ float GetZ(qword q) { float z; __asm__("pextuw %0,$0,%1" : "=r"(z) : "r"(q)); return z; }
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
