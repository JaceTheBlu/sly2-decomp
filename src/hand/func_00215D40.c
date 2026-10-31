#include "util.h"
struct S {
    int x0; unsigned char *pch; int x8; int xC; int x10;
    struct RGBA c1; struct RGBA c0; struct RGBA c2;
    char pad20[0x40]; int x60;
};
void func_002160D8(struct S *p);
unsigned char func_00215D40(struct S *p)
{
    int fDone = 0;
    p->x60 = 0;
    while (!fDone) {
        unsigned char *pch = p->pch;
        unsigned char c = *pch;
        if (c == '&') {
            if (pch[1] == c) {
                p->pch = pch + 1;
                fDone = 1;
            } else if (pch[1] == '.') {
                p->pch = pch + 2;
                p->x8 = p->xC;
                p->c1 = p->c0;
                p->x60 = 1;
                func_002160D8(p);
            } else {
                p->pch = pch + 2;
                p->x8 = p->x10;
                p->c1 = p->c2;
                p->x60 = 1;
                func_002160D8(p);
            }
        } else {
            fDone = 1;
        }
    }
    return *p->pch++;
}
