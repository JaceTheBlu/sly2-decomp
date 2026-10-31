struct AREQ { int cb; int cbAlign; };
struct E { char pad[0x10]; struct E *p10; struct E *p14; int x18; int x1C; };
struct P { char pad[0x4558]; int c; struct E *ae; int n; void *p4564; };
int func_00117C20(void *pbs);
void ReadVector4__18CBinaryInputStreamP7VECTOR4(void *pbs, struct E *pe);
int func_00117D50(void *pbs);
void *PvAllocSwClearImpl__FP7SWALLOC(struct AREQ *preq);
void func_0013E0E0(struct P *p, void *pbs)
{
    struct AREQ req;
    int i;
    int c = func_00117C20(pbs);
    req.cbAlign = 0x10;
    req.cb = c * sizeof(struct E);
    p->c = c;
    p->ae = (struct E *)PvAllocSwClearImpl__FP7SWALLOC(&req);
    p->n = 0;
    for (i = 0; i < p->c; i++) {
        struct E *pe = &p->ae[i];
        int j;
        ReadVector4__18CBinaryInputStreamP7VECTOR4(pbs, pe);
        j = func_00117D50(pbs);
        if (j >= 0)
            pe->p10 = &p->ae[j];
        else
            pe->x18 = p->n++;
        j = func_00117D50(pbs);
        if (j >= 0)
            pe->p14 = &p->ae[j];
        else
            pe->x1C = p->n++;
    }
    req.cbAlign = 0x10;
    req.cb = p->n * sizeof(struct E);
    p->p4564 = PvAllocSwClearImpl__FP7SWALLOC(&req);
}
