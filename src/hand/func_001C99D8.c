#include "dl.h"
struct N { int id; struct N *pnParent; int x8; int xC; int x10; struct N *pnNext; struct DL dl; int pad; };
struct AL { int cb; int cbAlign; };
extern char g_sw[];
void *PvAllocSwClearImpl__FP7SWALLOC(const struct AL *pal);
void func_0011A050(struct DL *pdl, int ib);
int func_001C9968(int id);
struct DL *func_0015E3C0(void *p, int id);
void func_0011A070(struct DL *pl, void *pv);
struct N *func_001C99D8(struct N *p, int c, const int *aid)
{
    struct N *pn, *pnParent, *pnNew;
    struct AL al;
    int i;
again:
    for (pn = (struct N *)p->dl.head; pn; pn = pn->pnNext) {
        if (pn->id == *aid) {
            if (c == 1) return pn;
            p = pn;
            c--;
            aid++;
            goto again;
        }
    }
    al.cb = c * sizeof(struct N);
    al.cbAlign = 0x10;
    pnNew = (struct N *)PvAllocSwClearImpl__FP7SWALLOC(&al);
    pnParent = p;
    for (i = 0; i < c; i++) {
        pn = &pnNew[i];
        func_0011A050(&pn->dl, 0x14);
        pn->id = aid[i];
        pn->x8 = func_001C9968(pn->id);
        func_0011A070(func_0015E3C0(g_sw, pn->x8), pn);
        pn->pnParent = pnParent;
        func_0011A070(&pnParent->dl, pn);
        pnParent = pn;
    }
    return pn;
}
