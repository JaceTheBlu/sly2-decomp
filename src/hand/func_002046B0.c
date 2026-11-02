#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
float func_002458F0(float y, float x);
void func_00204660(void *p, float g);
void func_002046B0(void *p, qword v) { func_00204660(p, func_002458F0(GetY(v), GetX(v))); }
