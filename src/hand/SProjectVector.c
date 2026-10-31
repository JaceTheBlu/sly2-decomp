typedef int qword __attribute__((mode(TI)));
float SProjectVector(qword a, qword b, qword *ppar, qword *pperp)
{
    qword d, one, p;
    float g;
    __asm__("vmul.xyz %0, %2, %3\n\tvaddw.x %1, $vf0, $vf0w\n\tvadday.x $ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z" : "=j"(d), "=j"(one) : "j"(a), "j"(b));
    __asm__("vmulx.xyzw %0, %1, %2x" : "=j"(p) : "j"(b), "j"(d));
    if (ppar) {
        __asm__("sq %1, %0" : "=m"(*ppar) : "r"(p));
    }
    if (pperp) {
        qword r;
        __asm__("vsub.xyzw %0, %1, %2" : "=j"(r) : "j"(a), "j"(p));
        *pperp = r;
    }
    __asm__("mtc1 %1, %0" : "=f"(g) : "r"(d));
    return g;
}
