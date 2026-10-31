typedef int qword __attribute__((mode(TI)));
typedef union { qword q; float f[4]; } VU;
typedef struct { VU r[3]; } M3;
struct A { char pad[0x10]; qword p0; char pad1[0x20]; qword p1; };
struct P { char pad[0x40]; char a40[0x20]; float t; char pad1[0xC]; float x, y, z; };
struct S { char pad[0x120]; int x120; char pad1[0x1C]; float g140; };
void *func_002333B4(void *p, int c, int n);
void CalculateTnCrv__FP2TNUxP7VECTOR4T2(struct S *ps, qword v, qword *pq, void *pv);
void CalculateTnPos__FP2TNP7VECTOR4ffP3CLQP2LM4FTNDPUx(struct S *ps, qword *pq, M3 *pm, void *pv, float g, float h, int f, qword *ppos);
void func_00220DD8(struct P *p, struct A *pa, qword *ppos, struct S *ps)
{
    VU u;
    float t = p->t;
    qword r, a, b;
    __asm__("qmtc2.ni %1, %0" : "=j"(a) : "r"(t));
    __asm__("qmtc2.ni %1, %0" : "=j"(b) : "r"(1.0f - t));
    u.q = b;
    __asm__("vmulax.xyzw $ACC, %1, %2x\n\tvmaddx.xyzw %0, %3, %4x" : "=j"(r) : "j"(pa->p0), "j"(b), "j"(pa->p1), "j"(a));
    *ppos = r;
    u.q = a;
    if (ps) {
        M3 m;
        char ab[0x10];
        int n;
        func_002333B4(&m, 0, 0x30);
        m.r[0].f[1] = p->x;
        m.r[1].f[1] = p->y;
        m.r[2].f[1] = p->z;
        n = ps->x120;
        ps->x120 = 0;
        CalculateTnCrv__FP2TNUxP7VECTOR4T2(ps, *ppos, &u.q, ab);
        CalculateTnPos__FP2TNP7VECTOR4ffP3CLQP2LM4FTNDPUx(ps, &u.q, &m, p->a40, ps->g140, 0.0f, 1, ppos);
        ps->x120 = n;
    }
}
