typedef int qword __attribute__((mode(TI)));
extern struct { float t; float dt; } g_clock;
extern float D_002C3DB8;
extern struct { char pad[0x4030]; int n4030; } g_sw;
struct X { char pad[0x30]; qword v; char pad2[4]; void *p44; char pad3[0xC]; int n54; };
struct S { char pad[0xE60]; int nE60; char pad2[0xF44 - 0xE64]; float t; };
qword func_001A62E8(void *p);
void func_00156548(int a, qword v, struct S *p, struct X **ppx);
struct X *func_00156698(int a, qword v, struct S *p);
void func_0020B140(struct S *p, void *q)
{
    struct X *px;
    qword v = func_001A62E8(q);
    px = 0;
    if (p->nE60)
        func_00156548(p->nE60, func_001A62E8(p), p, &px);
    else
        px = func_00156698(g_sw.n4030, func_001A62E8(p), p);
    px->v = v;
    px->p44 = q;
    px->n54 = 4;
    p->t = g_clock.t + D_002C3DB8;
}
