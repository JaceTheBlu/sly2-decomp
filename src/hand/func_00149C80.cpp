#include "clock.h"
struct CRef;
extern "C" void func_00129EC8(CRef *);
struct CRef {
    int m_tagk; int tag;
    ~CRef() { func_00129EC8(this); }
};
struct NODE;
extern char D_004520A8[];
extern "C" {
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pheap, void *pv);
void func_002550F8(void *pv);
}
struct SPM {
    NODE *p;
    ~SPM();
};
struct NODE {
    int cref;
    int x4;
    CRef ref;
    SPM pnext;
    void operator delete(void *pv) { func_002550F8(pv); FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pv); }
};
struct O { int cref; };
extern "C" void func_00257078(O *, int);
struct SP {
    O *p;
    SP(const SP &r);
    ~SP() { O *q = p; if (q && --q->cref == 0) func_00257078(q, 3); }
};
struct OSP { O *p; };
extern "C" {
int func_00256DD0(void);
SP Set__3SPFP5FRAME(int);
void func_00133000(void *pv, NODE *pn, O *po, int n);
}

struct CObj { virtual void Dummy(); };
struct CB {
    CObj *pobj;
    void (CObj::*pmf)(int);
    int arg;
    CB *pnext;
};
struct EV {
    float t;
    OSP *posp;
    NODE *pnode;
    int nC;
};
struct LIST { void *pvFirst; void *pvLast; int ib; };
extern CLOCK g_clock;

struct MGR {
    char pad[0x39F0];
    LIST levs;          /* 39F0 */
    char poolEv[0x3C90 - 0x39FC];
    char poolCb[0x3CA8 - 0x3C90];
    LIST lcbs;          /* 3CA8 */
};

extern "C" {
void func_0011A060(LIST *pl);
int func_0011A1E8(LIST *pl);
void func_0011A118(LIST *pl, void *pv);
void func_00149C80(MGR *p);
}

void func_00149C80(MGR *p)
{
    while (!func_0011A1E8(&p->lcbs)) {
        CB *pcb = (CB *)p->lcbs.pvFirst;
        func_0011A060(&p->lcbs);
        while (pcb) {
            void (CObj::*pmf)(int) = pcb->pmf;
            (pcb->pobj->*pmf)(pcb->arg);
            CB *pcbNext = pcb->pnext;
            FreeSlotheapPv__FP8SLOTHEAPPv(p->poolCb, pcb);
            pcb = pcbNext;
        }
    }

    EV *pev;
    while ((pev = (EV *)p->levs.pvFirst) != 0) {
        if (g_clock.t < pev->t)
            break;
        pev->nC = -1;
        OSP *posp = pev->posp;
        if (posp) {
            func_00133000(posp, pev->pnode, posp->p, 0);
        } else {
            int x = func_00256DD0();
            SP sp = Set__3SPFP5FRAME(x);
            func_00133000(p, pev->pnode, sp.p, 0);
        }
        func_0011A118(&p->levs, pev);
        NODE *pn = pev->pnode;
        if (--pn->cref == 0)
            delete pn;
        FreeSlotheapPv__FP8SLOTHEAPPv(p->poolEv, pev);
    }
}
