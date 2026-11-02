#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
extern float D_002C0AB0;
int func_001BC278(qword a, qword b, qword c)
{
    float g = (GetX(a) - GetX(b)) * (GetY(b) - GetY(c)) - (GetY(a) - GetY(b)) * (GetX(b) - GetX(c));
    if (g < -D_002C0AB0) return -1;
    if (D_002C0AB0 < g) return 1;
    return 0;
}
