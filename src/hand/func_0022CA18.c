typedef int qword __attribute__((mode(TI)));
static __inline__ qword Make(float x, float y, float z)
{
    qword q, t;
    __asm__("mfc1 %0,%2\n\tmfc1 %1,%3\n\tpextlw %0,%1,%0\n\tmfc1 %1,%4\n\tpcpyld %0,%1,%0"
            : "=&r"(q), "=&r"(t) : "f"(x), "f"(y), "f"(z));
    return q;
}
struct S { char pad[0x94]; int k; };
qword DecomposeRotateMatrixEuler__FP7MATRIX3(float *m);
qword func_0022CA18(struct S *p, float *m)
{
    qword v;
    union { qword q; float f; } r;
    switch (p->k) {
    case 0: case 15: break;
    case 1: case 4: case 5: case 9: case 10:
        r.q = Make(m[12], m[13], m[14]); v = r.q; break;
    case 6: case 7:
        v = DecomposeRotateMatrixEuler__FP7MATRIX3(m); break;
    case 11:
        r.q = Make(m[4], m[8], m[9]); v = r.q; break;
    case 12:
        r.q = Make(m[0], m[5], m[10]); v = r.q; break;
    }
    return v;
}
