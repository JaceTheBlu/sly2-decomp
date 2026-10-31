struct AREQ { int cb; int cbAlign; };
struct OBJ { int a[4]; OBJ(); ~OBJ(); };
struct T { char pad[0xE4]; int c; void *p; int pad2; int c2; void *q; };
extern "C" {
void *PvAllocStackClearImpl__FP7SWALLOC(AREQ *preq);
void *PvAllocSwCopyImpl__FP7SWALLOCPv(AREQ *preq, void *pv);
void func_00231170(T *t, void *p);
void func_0012EB78(T *t, void *p);
}
void func_0012EB78(T *t, void *p)
{
    OBJ obj;
    AREQ req;
    AREQ *preq = &req;
    req.cb = 0xA0;
    preq->cbAlign = 0x10;
    t->p = PvAllocStackClearImpl__FP7SWALLOC(preq);
    req.cb = 0x80;
    preq->cbAlign = 0x10;
    t->q = PvAllocStackClearImpl__FP7SWALLOC(preq);
    func_00231170(t, p);
    req.cb = t->c * 0x14;
    preq->cbAlign = 0x10;
    t->p = PvAllocSwCopyImpl__FP7SWALLOCPv(preq, t->p);
    req.cb = t->c2 * 0x10;
    preq->cbAlign = 0x10;
    t->q = PvAllocSwCopyImpl__FP7SWALLOCPv(preq, t->q);
}
