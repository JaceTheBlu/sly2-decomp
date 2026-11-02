#include "mat.h"
extern "C" void *func_0012E1F0(unsigned int cb);
extern "C" void *func_002333B4(void *pv, int b, unsigned int cb);
struct CBase {
    int k;
    int a1, a2, a3, a4, a5;
    void *operator new(unsigned int cb) { return func_0012E1F0(cb); }
    virtual void F();
};
struct C0 : CBase { int b[4]; C0() { k = 0; } virtual void F(); };
struct C1 : CBase { int x; int b[4]; C1() { k = 1; x = 2; } virtual void F(); };
struct C2 : CBase { int b[25]; C2() { k = 2; } virtual void F(); };
struct C3 : CBase { int b[1]; C3() { k = 3; } virtual void F(); };
struct C4 : CBase { int b[3]; C4() { k = 4; } virtual void F(); };
struct C5 : CBase { int b[5]; C5() { k = 5; } virtual void F(); };
struct C6 : CBase { int pad; MATRIX4 mat;
    C6() { k = 6; MATRIX4 *pm = &mat; func_002333B4(pm, 0, sizeof(*pm)); pm->mat[0][0] = pm->mat[1][1] = pm->mat[2][2] = pm->mat[3][3] = 1.0f; }
    virtual void F(); };
struct C7 : CBase { int b[1]; C7() { k = 7; } virtual void F(); };
struct C8 : CBase { int b[9]; C8() { k = 8; } virtual void F(); };
struct C9 : CBase { int b[5]; C9() { k = 9; a5 = 0x14; } virtual void F(); };
extern "C" CBase *func_0012E238(int k);
CBase *func_0012E238(int k)
{
    CBase *p;
    switch (k) {
    case 0: p = new C0; break;
    case 1: p = new C1; break;
    case 2: p = new C2; break;
    case 3: p = new C3; break;
    case 4: p = new C4; break;
    case 5: p = new C5; break;
    case 6: p = new C6; break;
    case 7: p = new C7; break;
    case 8: p = new C8; break;
    case 9: p = new C9; break;
    default: p = 0; break;
    }
    return p;
}
