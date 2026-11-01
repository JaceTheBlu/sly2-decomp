typedef struct AREQ { int cb; int cbAlign; } AREQ;
typedef struct REC { int id; float v[2]; float g; } REC;
typedef struct T { char pad[0xE4]; int c; void *pad2; void **ap; int crec; REC *arec; } T;
typedef struct G { char pad[0x228]; void *p; } G;
extern G g_sndmgr;
void PostLoLoad__FP2LO(T *t);
void **PvAllocSwClearImpl__FP7SWALLOC(AREQ *preq);
void *func_001FE990(G *pg, int id);
void func_001FC408(float g, void *p, void *q, T *t, float *pv);
void PostCid43Load(T *t)
{
    AREQ req;
    void *p;
    PostLoLoad__FP2LO(t);
    req.cb = t->c * 4;
    req.cbAlign = 0x10;
    t->ap = PvAllocSwClearImpl__FP7SWALLOC(&req);
    p = g_sndmgr.p;
    if (p) {
        int i;
        for (i = 0; i < t->crec; i++) {
            REC *prec = &t->arec[i];
            func_001FC408(prec->g, p, func_001FE990(&g_sndmgr, prec->id), t, prec->v);
        }
    }
}
