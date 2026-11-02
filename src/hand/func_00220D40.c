#include "vu0.h"
struct S { int a; float b; int c[2]; float d; int e[3]; float f; int g[3]; float h; char pad[0x54]; float i, j; };
extern float D_002A96E0, D_002A96E4;
extern char D_002C41B0[];
float func_002458F0(float y, float x);
float func_0011D948(void *p, float f);
void func_00220D40(struct S *p)
{
    if (p->i == D_002A96E0 && p->j == D_002A96E4) {
        float a = p->b + p->d;
        float f = func_002458F0(p->h, GSqrt(a * a + p->f * p->f));
        f = func_0011D948(D_002C41B0, f);
        p->j = f;
        p->i = f;
    }
}
