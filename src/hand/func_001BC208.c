#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
int func_001BC208(qword a, qword b)
{
    if (GetX(a) < GetX(b)) return -1;
    if (GetX(b) < GetX(a)) return 1;
    if (GetY(a) < GetY(b)) return -1;
    if (GetY(b) < GetY(a)) return 1;
    return 0;
}
