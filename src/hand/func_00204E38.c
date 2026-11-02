typedef int qword __attribute__((mode(TI)));
typedef struct { short d; short pad; void *pfn; } VTE;
extern qword D_002A2DD0;
struct O { VTE *vt; };
struct X { int a; struct O *po; };
struct TABLE;
struct Q { char pad[0x14]; struct TABLE *table; char pad2[0x40 - 0x18]; float g40; };
int func_00131968(struct Q *q);
struct X *PchnFindAseg__FP4ASEGP3ALOii(struct TABLE *table, void *owner, int kind, int check);
qword func_00204E38(void *p, struct Q *q, float g)
{
    qword r = D_002A2DD0;
    if (q && !func_00131968(q)) {
        struct X *x = PchnFindAseg__FP4ASEGP3ALOii(q->table, p, 1, 1);
        if (x) {
            struct O *o = x->po;
            ((void (*)(void *, qword *, qword *, float, float))o->vt[3].pfn)((char *)o + o->vt[3].d, 0, &r, g, q->g40);
        }
    }
    return r;
}
