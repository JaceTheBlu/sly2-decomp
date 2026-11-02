struct PMF { short delta; short pad; int (*pfn)(void *); };
struct S { int x0; int x4; struct PMF pmf; int x10; };
struct ThreadParam { int attr; void *entry; void *stack; int stackSize; void *gpReg; int initPriority; int currentPriority; unsigned int attr2; int option; int waitType; int waitId; int wakeupCount; };
extern char D_002E5270[], D_002E2080[];
extern int D_004425D8[];
void func_001AAF18(struct S *s);
void SetMemcardThreadHighPrio__FP7MEMCARD(struct S *s);
void *func_002333B4(void *p, int c, unsigned int n);
int func_00234820(struct ThreadParam *tp);
void func_002355E0(int id, void *arg);
void CreateMemcardThread__FP7MEMCARDii(struct S *s, struct PMF pmf)
{
    struct ThreadParam tp;
    SetMemcardThreadHighPrio__FP7MEMCARD(s);
    s->pmf = pmf;
    s->x10 = 0x21;
    func_002333B4(&tp, 0, sizeof(tp));
    tp.entry = func_001AAF18;
    tp.stack = D_002E2080;
    tp.gpReg = D_002E5270;
    tp.stackSize = 0x4000;
    tp.initPriority = 3;
    s->x4 = func_00234820(&tp);
    D_004425D8[0] = s->x4;
    func_002355E0(s->x4, s);
}
