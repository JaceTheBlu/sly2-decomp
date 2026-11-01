typedef struct MSG { int cb; int nKind; } MSG;
void *PvAllocSwClearImpl__FP7SWALLOC(MSG *pmsg);
static inline void *PvAllocMsg(MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwClearImpl__FP7SWALLOC(pmsg); }
struct E { char *pchz; int n4; int n8; int nC; char ab[0x40]; };
struct S { char pad[0x50]; int c; struct E *ae; };
extern char g_heapSw[];
void LoadLoFromBrx__FP2LOP18CBinaryInputStream(struct S *p, void *pbis);
int func_00117BD0(void *pbis);
int func_00117D00(void *pbis);
int func_00117DB8(void *pbis);
void func_00118380(void *pbis, char **ppchz, void *palloc, int nKind);
void func_00118458(void *pbis, void *pv);
void func_00153B08(struct S *p, void *pbis)
{
    MSG msg;
    int i;
    LoadLoFromBrx__FP2LOP18CBinaryInputStream(p, pbis);
    p->c = func_00117BD0(pbis);
    p->ae = PvAllocMsg(&msg, p->c * sizeof(struct E), 0x10);
    for (i = 0; i < p->c; i++) {
        struct E *pe = &p->ae[i];
        func_00118380(pbis, &pe->pchz, g_heapSw, 7);
        pe->n4 = func_00117D00(pbis);
        pe->n8 = func_00117DB8(pbis);
        pe->nC = func_00117DB8(pbis);
        func_00118458(pbis, pe->ab);
    }
}
