#include "mat.h"
typedef int qword __attribute__((mode(TI)));
typedef struct B7 { qword aq[7]; } B7;
extern MATRIX4 D_002DE5B0;
extern B7 D_002DE5F0;
struct S { int a; int b; int pad[2]; MATRIX4 m; B7 b7; char pad2[0x100 - 0xC0]; };
void *func_002333B4(void *pv, int b, int cb);
void func_00159118(struct S *p)
{
    func_002333B4(p, 0, sizeof(struct S));
    p->a = 1;
    p->b = -1;
    p->m = D_002DE5B0;
    p->b7 = D_002DE5F0;
}
