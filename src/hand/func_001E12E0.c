#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct CMD { char pad[0x10]; qword q; float x, y, z; int pad2; float f; int pad3[3]; union { float g; int n; } u40; int n44; };
struct CMD *func_001E01F8(void *pq, int kind, int b);
void func_001E12E0(void *pq, qword a, qword v, int m, int n, float f)
{
    struct CMD *p = func_001E01F8(pq, 0x39, 1);
    p->q = a;
    p->x = GetX(v) * 0.017453294f;
    p->y = GetY(v) * 0.017453294f;
    p->z = GetZ(v) * 0.017453294f;
    p->f = f;
    p->u40.n = m;
    p->n44 = n;
}
