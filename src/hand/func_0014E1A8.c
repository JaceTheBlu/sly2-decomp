typedef int qword __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } V4;
typedef struct { V4 r[3]; } M3 __attribute__((aligned(16)));
typedef struct { M3 m; V4 pos; } M4;
struct CM { char pad[0x60]; M4 mat; };
void DecomposeSphere__FUxPfN21(qword v, float *a, float *b, int c);
M3 func_0011B720(float a, float b);
void __as__6VECTORG9VU_VECTOR(V4 *p, qword v);
void func_0014DC58(struct CM *p);
static __inline__ void LoadM4(M4 *pm, M3 m, qword pos)
{
    __as__6VECTORG9VU_VECTOR(&pm->pos, pos);
    pm->m = m;
    pm->m.r[1].w = 0;
    pm->m.r[2].w = 0;
    pm->m.r[0].w = 0;
    pm->pos.w = 1.0f;
}
void func_0014E1A8(struct CM *p, qword pos, qword tgt, float da, float db)
{
    qword d;
    float a, b;
    __asm__("vsub.xyzw %0, %1, %2" : "=j"(d) : "j"(tgt), "j"(pos));
    DecomposeSphere__FUxPfN21(d, &a, &b, 0);
    LoadM4(&p->mat, func_0011B720(a + da, b + db), pos);
    func_0014DC58(p);
}
