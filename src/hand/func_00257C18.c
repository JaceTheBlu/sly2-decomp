typedef struct N { int x0; unsigned prev : 13; unsigned prevpg : 2; unsigned p1 : 1; unsigned next : 13; unsigned nextpg : 2; unsigned mark : 1; } N;
extern char *D_00452160[4];
extern char D_00452170[];
extern N *D_002DD2D0, *D_002DD2D8;
extern unsigned int D_002DD598[1];
void func_00256120(N *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);

static inline N *Ptr(unsigned idx, unsigned pg)
{
    if (idx == 0 && pg == 0)
        return 0;
    return (N *)(D_00452160[pg] + idx * 0x14);
}

static inline N *Next(N *p)
{
    return Ptr(p->next, p->nextpg);
}

void func_00257C18(void)
{
    N *p;
    p = D_002DD2D0;
    while (p != D_002DD2D8) {
        N *n;
        if (p->mark != D_002DD598[0])
            p->mark = D_002DD598[0];
        n = Next(p);
        p = n;
    }
    while (p) {
        N *cur = p;
        N *next = Next(cur);
        p = next;
        if (cur->mark != D_002DD598[0]) {
            func_00256120(cur);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_00452170, cur);
        }
    }
}
