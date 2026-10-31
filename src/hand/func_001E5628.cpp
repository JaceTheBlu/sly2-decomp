#include "clock.h"
struct VTE { short d; short pad; void (*pfn)(void *); };
struct Q { char pad[0x5C]; int dl; };
struct P { int pad[3]; VTE *vt; int pad10; Q *pq; char pad2[0x9C - 0x18]; int x9C; char pad3[0xEC - 0xA0]; void *pvEC; };
class LOCK {
public:
    P *m_p;
    LOCK(P *p) : m_p(p) { p->vt[1].pfn((char *)p + p->vt[1].d); }
    ~LOCK() { m_p->vt[2].pfn((char *)m_p + m_p->vt[2].d); }
};
extern "C" {
extern CLOCK g_clock;
int func_001E5778(P *p);
void func_0011A2E8(int *pdl, P *p);
void func_001E5370(P *p);
void func_001E53D8(P *p);
void func_001E5410(P *p);
void func_001E5468(P *p);
void func_001E54B0(P *p);
void func_001E54E8(P *p);
void func_001E5570(P *p);
void SetClockRate__FP5CLOCK3CRKf(CLOCK *pclock, int n, float g);
void func_001E4EB8(P *p, int a, int b);
void SetJsgTn__FP3JSGP2TN(P *p, void *po);
void SetJsgFocus__FP3JSGP2LO(P *p, int a);
void func_001E50E0(P *p, int a, int b);
void func_001FB098(void *pv, float g);
void func_00258040(void **ppv, int n);
void func_001E5A98(P *p, int n);
void func_001E5628(P *p);
}
void func_001E5628(P *p)
{
    if (func_001E5778(p)) return;
    LOCK lock(p);
    void **ppv = &p->pvEC;
    func_0011A2E8(&p->pq->dl, p);
    func_001E5370(p);
    func_001E53D8(p);
    func_001E5410(p);
    func_001E5468(p);
    func_001E54B0(p);
    func_001E54E8(p);
    func_001E5570(p);
    SetClockRate__FP5CLOCK3CRKf(&g_clock, 6, 1.0f);
    func_001E4EB8(p, 0, 0);
    SetJsgTn__FP3JSGP2TN(p, 0);
    SetJsgFocus__FP3JSGP2LO(p, 0);
    func_001E50E0(p, 0, 0);
    if (*ppv) {
        func_001FB098(*ppv, 0.0f);
        func_00258040(ppv, 0);
    }
    if (p->x9C) func_001E5A98(p, 1);
    p->vt[2].pfn((char *)p + p->vt[2].d);
}
