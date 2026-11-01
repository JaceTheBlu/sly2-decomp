#include "dl.h"
struct S { char pad[0x58]; int n58; struct DL dl; };
void InitLo__FP2LO(struct S *p);
void InitDl__FP2DLi(struct DL *pdl, int ib);
void func_001DFAD8(struct S *p) {
    InitLo__FP2LO(p);
    p->n58 = -1;
    InitDl__FP2DLi(&p->dl, 0xE4);
}
