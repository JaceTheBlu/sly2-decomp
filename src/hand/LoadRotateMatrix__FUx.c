typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f; } U;
typedef struct { qword r[3]; } M3;
extern M3 D_002A2D00;
M3 *LoadRotateMatrixRad__FfUx(M3 *pm, float g, qword axis);
void *func_0023320C(void *pvDst, void *pvSrc, int cb);
M3 *LoadRotateMatrix__FUx(M3 *pm, qword v)
{
    qword d, one, l;
    float g;
    __asm__("vmul.xyz %0, %2, %2\n\tvaddw.x %1, $vf0, $vf0w\n\tvadday.x $ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(d), "=j"(one) : "j"(v));
    __asm__("vsqrt $Q, %1x\n\tvwaitq\n\tvaddq.x %0, $vf0, $Q" : "=j"(l) : "j"(d));
    __asm__("mtc1 %1, %0" : "=f"(g) : "r"(l));
    if (g < 1.0e-4f) {
        func_0023320C(pm, &D_002A2D00, sizeof(M3));
    } else {
        M3 m;
        U s;
        qword n;
        __asm__("qmtc2.ni %1, %0" : "=j"(s.q) : "r"(g));
        __asm__("vdiv $Q, $vf0w, %1x\n\tvwaitq\n\tvmulq.xyzw %0, %2, $Q" : "=j"(n) : "j"(s.q), "j"(v));
        LoadRotateMatrixRad__FfUx(&m, g, n);
        func_0023320C(pm, &m, sizeof(M3));
    }
    return pm;
}
