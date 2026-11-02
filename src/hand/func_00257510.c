typedef struct N { int x0; unsigned prev : 13; unsigned prevpg : 2; unsigned p1 : 1; unsigned next : 13; unsigned nextpg : 2; unsigned mark : 1; } N;
extern char *D_004520E8[4];
extern char D_004520F8[];
extern N *D_002DD2A0, *D_002DD2A8;
extern unsigned int D_002DD598[1];
void func_00255770(N *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);

static inline N *Ptr(unsigned idx, unsigned pg)
{
    if (idx == 0 && pg == 0)
        return 0;
    return (N *)(D_004520E8[pg] + idx * 0x28);
}

static inline N *Next(N *p)
{
    return Ptr(p->next, p->nextpg);
}

void func_00257510(void)
{
    N *p;
    p = D_002DD2A0;
    while (p != D_002DD2A8) {
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
            func_00255770(cur);
            FreeSlotheapPv__FP8SLOTHEAPPv(D_004520F8, cur);
        }
    }
}
