struct E { int id; int cref; struct E *pnext; };
struct S { int pad[2]; struct E *pfirst; };
extern char D_003E1144[];
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
void func_001334A8(struct S *p) {
    struct E *pe = p->pfirst;
    while (pe) { struct E *pNext = pe->pnext; FreeSlotheapPv__FP8SLOTHEAPPv(D_003E1144, pe); pe = pNext; }
    p->pfirst = 0;
}
