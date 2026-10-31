// MATCH: hard-register VF locals; clock pointer pinned to v0 and the second dt read via a v0-pinned int.
typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f[4]; } VU;
struct CLOCK { float t; union { float g; int n; } dt; };
extern struct CLOCK g_clock;
struct P { char pad[0x300]; int f300; };
void SpringCm__FP2CMPUxP6VECTORUxff(struct P *p, qword *ppos, float *pvel, qword target, float k1, float k2)
{
    register struct CLOCK *pclock __asm__("v0");
    register qword s1 __asm__("vf3");
    register qword s2 __asm__("vf4");
    register qword s3 __asm__("vf5");
    register qword d __asm__("vf1");
    register qword v __asm__("vf2");
    if (p->f300) {
        *ppos = target;
        pvel[2] = 0.0f;
        pvel[1] = 0.0f;
        pvel[0] = 0.0f;
        return;
    }
    pclock = &g_clock;
    __asm__("qmtc2.ni %1, %0" : "=j"(s1) : "r"(k1));
    d = *ppos;
    __asm__("qmtc2.ni %1, %0" : "=j"(s2) : "r"(k2));
    __asm__("vsub.xyzw %0, %1, %0" : "+j"(d) : "j"(target));
    __asm__("qmtc2.ni %1, %0" : "=j"(s3) : "r"(pclock->dt.n));
    v = *(qword *)pvel;
    __asm__("vmulax.xyzw ACC, %0, %2x\n\tvmaddx.xyzw %0, %1, %3x" : "+j"(d) : "j"(v), "j"(s1), "j"(s2));
    { VU u; u.q = s1; }
    __asm__("vadda.xyzw ACC, %0, $vf0\n\tvmaddx.xyzw %0, %1, %2x" : "+j"(v) : "j"(d), "j"(s3));
    { VU u; u.q = s2; }
    *(qword *)pvel = v;
    {
        register qword s4 __asm__("vf3");
        qword x;
        { register int n __asm__("v0") = pclock->dt.n;
        __asm__("qmtc2.ni %1, %0" : "=j"(s4) : "r"(n)); }
        x = *ppos;
        { VU u; u.q = s3; }
        __asm__("vadda.xyzw ACC, %0, $vf0\n\tvmaddx.xyzw %0, %1, %2x" : "+j"(x) : "j"(v), "j"(s4));
        { VU u; u.q = s4; }
        *ppos = x;
    }
}
