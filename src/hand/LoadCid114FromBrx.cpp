#include "vu0.h"
struct MSG { int cb; int nKind; };
struct FRAME {
    int a[4];
    FRAME();
    ~FRAME();
};
struct ENT { char a[0x50]; };
struct OBJ {
    char pad[0x50];
    int c;
    ENT *ae;
    int cMax;
    char pad5c[0x7C - 0x5C];
    int f7C;
};
void *PvAllocStackImpl__FP7SWALLOC(MSG *);
void *PvAllocSwImpl__Fi(MSG *);
void func_001AE5A0(void *, void *, int);
void func_001E0290(OBJ *, int);
void LoadLoFromBrx__FP2LOP18CBinaryInputStream(OBJ *, void *);
extern "C" void LoadCid114FromBrx(OBJ *p, void *x)
{
    FRAME frame;
    MSG msg;
    MSG *pmsg = &msg;
    pmsg->cb = 0xA000;
    pmsg->nKind = 0x10;
    p->ae = (ENT *)PvAllocStackImpl__FP7SWALLOC(pmsg);
    func_001E0290(p, -1);
    p->f7C = 1;
    LoadLoFromBrx__FP2LOP18CBinaryInputStream(p, x);
    {
        ENT *aeOld = p->ae;
        p->cMax = NMax(p->c, p->cMax) + 1;
        pmsg->cb = p->cMax * sizeof(ENT);
        pmsg->nKind = 0x10;
        p->ae = (ENT *)PvAllocSwImpl__Fi(pmsg);
        func_001AE5A0(p->ae, aeOld, p->c * sizeof(ENT));
    }
}
