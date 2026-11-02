typedef int qword __attribute__((mode(TI)));
extern struct { float t; float dt; } g_clock;
typedef struct { int k; int pad[7]; qword q; int pad2[4]; } MSG;
struct TGT;
typedef struct { short d; short pad; void (*pf)(struct TGT *, MSG *); } VTE;
typedef struct TGT { char pad[0xC]; VTE *vt; } TGT;
typedef struct {
    char pad0[0x70];
    qword x70;
    char pad80[0xF0 - 0x80];
    TGT *xF0;
    float xF4;
    float xF8;
} OBJ;
void func_001CF268(OBJ *);
void func_001D1160(OBJ *p)
{
    func_001CF268(p);
    if (p->xF0) {
        p->xF8 += g_clock.dt * p->xF4;
        while (p->xF8 >= 1.0f) {
            MSG m;
            TGT *t;
            m.k = 4;
            m.q = p->x70;
            t = p->xF0;
            t->vt[51].pf((TGT *)((char *)t + t->vt[51].d), &m);
            p->xF8 -= 1.0f;
        }
    }
}
