typedef struct AREQ { int cb; int cbAlign; } AREQ;
typedef struct KEY { float a, b; } KEY;
typedef struct T { int pad; int c; float *at; KEY *ak[3]; int pad2[2]; int v[4]; } T;
void ReadVector__18CBinaryInputStreamP6VECTOR(void *pbis, void *pv);
int func_00117C20(void *pbis);
int func_00117BD0(void *pbis);
float func_00117E38(void *pbis);
void *PvAllocSwImpl__Fi(AREQ *preq);
void func_0012C570(T *t, void *pbis)
{
    AREQ req;
    int i, j, mask, grf;
    int c;
    ReadVector__18CBinaryInputStreamP6VECTOR(pbis, t->v);
    c = func_00117C20(pbis);
    req.cb = c * 4;
    req.cbAlign = 0x10;
    t->c = c;
    t->at = PvAllocSwImpl__Fi(&req);
    for (i = 0; i < t->c; i++)
        t->at[i] = func_00117C20(pbis) * 0.016666668f;
    grf = func_00117BD0(pbis);
    for (j = 0, mask = 1; j < 3; j++, mask <<= 1) {
        if (mask & grf) {
            KEY *ak;
            req.cb = t->c * 8;
            req.cbAlign = 0x10;
            ak = PvAllocSwImpl__Fi(&req);
            t->ak[j] = ak;
            for (i = 0; i < t->c; i++) {
                ak[i].a = func_00117E38(pbis);
                ak[i].b = func_00117E38(pbis);
            }
        }
    }
}
