#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct CMD { char pad[0x10]; qword q; float x, y, z; int pad2; float f; };
struct CMD *func_001E01F8(void *pq, int kind, int b);
void func_001E1488(void *pq, qword a, qword v, float f)
{
    struct CMD *p = func_001E01F8(pq, 0x3F, 1);
    p->q = a;
    p->x = GetX(v) * 0.017453294f;
    p->y = GetY(v) * 0.017453294f;
    p->z = GetZ(v) * 0.017453294f;
    p->f = f;
}
