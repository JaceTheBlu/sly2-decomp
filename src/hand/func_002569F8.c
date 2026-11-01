#include "vtable.h"
typedef struct A { VTE *vt; } A;
typedef struct E { unsigned int key; int k; int v; struct E *next; } E;
typedef struct H { unsigned int c; E **ap; int count; A *pa; } H;
void *func_002333B4(void *, int, int);
void func_002568C0(H *, int);
unsigned int func_0011AFE0(int);

int *func_002569F8(H *h, int *pk, int *pv)
{
    unsigned int hash, i;
    E *e;
    h->count++;
    if (h->c == 0)
        func_002568C0(h, 0x35);
    hash = func_0011AFE0(*pk);
    i = hash % h->c;
    e = ((E *(*)(void *, int, int))h->pa->vt[1].pfn)((char *)h->pa + h->pa->vt[1].delta, 0x10, 3);
    func_002333B4(e, 0, 0x10);
    e->key = hash;
    e->k = *pk;
    e->v = *pv;
    e->next = h->ap[i];
    h->ap[i] = e;
    return &e->v;
}
