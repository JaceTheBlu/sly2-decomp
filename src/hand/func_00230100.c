#include "vtable.h"
typedef struct N { char pad[0x10]; struct N *next; int x14; VTE *vt; } N;
typedef struct S { char pad[0x90]; N *first; } S;
void func_0022C840(void *, S *);

#define VCALL(o, k) ((void (*)(void *))(o)->vt[k].pfn)((char *)(o) + (o)->vt[k].delta)

void func_00230100(void *ctx, S *s, N *n)
{
    N *head = s->first;
    N **pp = &s->first;
    N *e;
    for (e = head; e; e = e->next) {
        if (e == n) {
            *pp = e->next;
            if (s->first != head) {
                func_0022C840(ctx, s);
                VCALL(head, 2);
                if (s->first)
                    VCALL(s->first, 1);
            } else if (head) {
                VCALL(head, 3);
            }
            return;
        }
        pp = &e->next;
    }
}
