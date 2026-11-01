#include "mat.h"
typedef int qword __attribute__((mode(TI)));
typedef struct B7 { qword aq[7]; } B7;
struct X { int a; int b; int c; int pad; MATRIX4 m; B7 b7; MATRIX4 m2; };
struct Y { int a; int b; int c; };
void func_00159118(struct X *px);
void func_0015BD20(void *p, struct X *px, struct Y *py);
void func_002333B4(void *pv, int b, int cb);
void func_0015BE28(qword q0, qword q1, void *p, MATRIX4 *pm, B7 *pb7, int n1, int n2, int n3)
{
    struct X x;
    struct Y y;
    func_00159118(&x);
    func_002333B4(&y, 0, sizeof(y));
    x.m.r[2] = q0;
    x.m.r[3] = q1;
    x.b7 = *pb7;
    x.c = n1;
    y.b = n2;
    y.c = n3;
    x.b = 1;
    x.m2 = *pm;
    func_0015BD20(p, &x, &y);
}
