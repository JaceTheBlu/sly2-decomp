typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f[4]; } U;
typedef struct { float m[3][4]; } MATRIX3;
static __inline__ qword Make(float x, float y, float z)
{
    qword q, t;
    __asm__("mfc1 %0,%2\n\tmfc1 %1,%3\n\tpextlw %0,%1,%0\n\tmfc1 %1,%4\n\tpcpyld %0,%1,%0"
            : "=&r"(q), "=&r"(t) : "f"(x), "f"(y), "f"(z));
    return q;
}
float func_0011CFE0(float g, float gLimit);
float func_002457F0(float g);
float func_002458F0(float y, float x);
qword DecomposeRotateMatrixEuler__FP7MATRIX3(MATRIX3 *pmat)
{
    U r;
    qword q;
    float tilt = func_002457F0(func_0011CFE0(-pmat->m[0][2], 1.0f));
    if (tilt < 1.5706963539123535f) {
        if (-1.5706963539123535f < tilt) {
            float x = func_002458F0(pmat->m[1][2], pmat->m[2][2]);
            r.q = Make(x, tilt, func_002458F0(pmat->m[0][1], pmat->m[0][0]));
            q = r.q;
        } else {
            r.q = Make(0.0f, tilt, func_002458F0(-pmat->m[1][0], -pmat->m[2][0]));
            q = r.q;
        }
    } else {
        r.q = Make(0.0f, tilt, func_002458F0(-pmat->m[1][0], pmat->m[2][0]));
        q = r.q;
    }
    return q;
}
