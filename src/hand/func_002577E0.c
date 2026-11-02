typedef struct N { int x0; unsigned prev : 13; unsigned prevpg : 2; unsigned p1 : 1; unsigned next : 13; unsigned nextpg : 2; unsigned mark : 1; } N;
extern char *D_00452098[4];
extern char D_004520A8[];
extern N *D_002DD280, *D_002DD288;
extern unsigned int D_002DD598[1];
void func_002550F8(N *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);

static inline N *Ptr(unsigned idx, unsigned pg)
{
    if (idx == 0 && pg == 0)
        return 0;
    return (N *)(D_00452098[pg] + idx * 0x14);
}

static inline N *Next(N *p)
{
    return Ptr(p->next, p->nextpg);
}

void func_002577E0(void)
{
    N *p;
    p = D_002DD280;
    while (p != D_002DD288) {
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
            func_002550F8(cur);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, cur);
        }
    }
}
