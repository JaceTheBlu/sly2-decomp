typedef int qword __attribute__((mode(TI)));
struct MSG { int cb; int nKind; };
struct E { qword pos; float x10; long k:4; long m:8; struct S *child; int x1C; };
struct S { struct E ae[4]; };
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *pmsg);
static inline void *PvAllocMsg(struct MSG *pmsg, int cb, int nKind) { pmsg->cb = cb; pmsg->nKind = nKind; return PvAllocSwClearImpl__FP7SWALLOC(pmsg); }
struct S *func_001D6480(void) {
    struct MSG msg;
    struct S *p = PvAllocMsg(&msg, 0x80, 0x10);
    p->ae[0].k = p->ae[1].k = p->ae[2].k = p->ae[3].k = -1;
    return p;
}
