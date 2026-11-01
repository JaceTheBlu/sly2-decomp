#include "vtable.h"
typedef struct A { VTE *vt; } A;
typedef struct E { int key; int k; int v; struct E *next; } E;
typedef struct H { int c; E **ap; int count; A *pa; } H;
void *func_002333B4(void *, int, int);

#define FREE(pa, p) ((void (*)(void *, void *))(pa)->vt[3].pfn)((char *)(pa) + (pa)->vt[3].delta, p)

void func_002567D0(H *h)
{
    int i;
    for (i = 0; i < h->c; i++) {
        E *e = h->ap[i];
        while (e) {
            E *next = e->next;
            FREE(h->pa, e);
            e = next;
        }
    }
    func_002333B4(h->ap, 0, h->c * 4);
    h->count = 0;
    FREE(h->pa, h->ap);
    h->c = 0;
    h->ap = 0;
}
