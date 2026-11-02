#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct C { char pad[0x88]; float g88; };
struct B { char pad[0xE8]; struct C *pc; };
struct S { struct B *pb; };
int CSolveQuadratic__FfffPf(float, float, float, float *);
int func_0019A400(struct S *p, qword a, qword b, qword c, qword d, float *pg) {
    float ag[2];
    int n = CSolveQuadratic__FfffPf(p->pb->pc->g88 * 0.5f, GetZ(b) - GetZ(d), GetZ(a) - GetZ(c), ag);
    if (n <= 0) return 0;
    {
        float g = ag[n - 1];
        if (g <= 0.0f) return 0;
        *pg = g;
    }
    return 1;
}
