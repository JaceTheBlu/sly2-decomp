struct E { int id; int cref; struct E *pnext; };
struct S { int pad[2]; struct E *pfirst; };
extern char D_003E1144[];
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
void func_00133448(struct S *p, int id) {
    struct E **ppe;
    struct E *pe;
    for (ppe = &p->pfirst; (pe = *ppe) != 0; ppe = &pe->pnext) { if (pe->id == id) { if (--pe->cref <= 0) { *ppe = pe->pnext; FreeSlotheapPv__FP8SLOTHEAPPv(D_003E1144, pe); } break; } }
}
