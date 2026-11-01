#include "vtable.h"
struct VT { VTE a[6]; };
struct Q { char pad[0xC]; VT *pvt; };
struct P { char pad[0xC]; VT *pvt; char pad2[0x28 - 0x10]; Q *pq; };
extern "C" void func_00133508(P *, int, int);
struct Lock {
    P *p;
    Lock(P *pp) { p = pp; ((void (*)(void *))p->pvt->a[1].pfn)((char *)p + p->pvt->a[1].delta); }
    ~Lock() { ((void (*)(void *))p->pvt->a[2].pfn)((char *)p + p->pvt->a[2].delta); }
};
extern "C" void func_001F0FD8(P *p, int a, int b)
{
    Lock l(p);
    Q *q = p->pq;
    if (q) ((void (*)(void *, int, int))q->pvt->a[5].pfn)((char *)q + q->pvt->a[5].delta, a, b);
    func_00133508(p, a, b);
}
