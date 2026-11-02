#include "vtable.h"
#include "mat.h"
typedef int qword __attribute__((mode(TI)));
struct K { int a; int b; };
extern struct K D_002A4D10;
struct G { char pad[0x3BF4]; int grf; char pad2[0x3D58 - 0x3BF8]; int cid; };
extern struct G g_sw;
struct AREQ { int cb; int cbAlign; };
struct SO { float m[0x40 / 4]; char pad[0x94 - 0x40]; int x94; char pad2[0xA4 - 0x98]; int id; };
struct O { void *pad[3]; struct VTE *vt; };
struct P {
    int pad[3]; struct VTE *vt; char pad1[0x54 - 0x10]; struct SO *pso;
    char pad2[0x1088 - 0x58]; int x1088; char pad3[4]; struct O **apo; int cpo;
};
extern char D_002BC9F0[];
void PostStepLoad__FP4STEP(struct P *);
void func_001A64E8(struct P *, int, void *);
void func_001959C0(void *);
void func_001910F8(void *);
void func_0019F3F0(void *);
void func_001A1098(void *);
void func_0019CC30(void *);
void func_0021F388(void *);
void func_0019DE58(void *);
int func_0015E650(struct G *, int, int, struct P *, int, void **);
void *PvAllocSwClearImpl__FP7SWALLOC(struct AREQ *);
void func_00141EF8(struct P *);
void func_001440D0(struct P *, int);
int func_001F8278(struct P *);
void func_001F35C8(struct P *, float);
qword func_001A62E8(struct P *);
struct MATRIX3 *func_001A6318(struct P *);
void *func_002333B4(void *, int, int);
void func_00149A50(struct G *, struct P *, struct K, int);

void func_001400B8(struct P *p)
{
    void *apv[16];
    int c;
    int i;

    PostStepLoad__FP4STEP(p);
    func_001A64E8(p, 0x35, D_002BC9F0);
    func_001959C0((char *)p + 0x2C0);
    func_001910F8((char *)p + 0x4C0);
    func_0019F3F0((char *)p + 0x9E0);
    func_001A1098((char *)p + 0xDF0);
    func_0019CC30((char *)p + 0xF00);
    func_0021F388((char *)p + 0x11B0);
    func_0019DE58((char *)p + 0xF50);
    c = func_0015E650(&g_sw, 0x401, 0x2AB, p, 0x10, apv);
    if (c) {
        struct AREQ req;
        struct AREQ *preq = &req;
        preq->cb = c * 8;
        p->cpo = c;
        preq->cbAlign = 0x10;
        p->apo = PvAllocSwClearImpl__FP7SWALLOC(preq);
        for (i = 0; i < c; i++) {
            struct O *po;
            struct VTE *e;
            p->apo[i * 2] = apv[i];
            po = p->apo[i * 2];
            e = &po->vt[9];
            ((void (*)(void *))e->pfn)((char *)po + e->delta);
        }
    }
    {
        struct VTE *e = &p->vt[79];
        ((void (*)(void *, int))e->pfn)((char *)p + e->delta, 0);
    }
    {
        struct VTE *e = &p->vt[104];
        ((void (*)(void *))e->pfn)((char *)p + e->delta);
    }
    func_00141EF8(p);
    func_001440D0(p, g_sw.grf & 4);
    p->x1088 = func_001F8278(p);
    func_001F35C8(p, 0.25f);
    if (p->pso->x94 == 0) {
        qword q = func_001A62E8(p);
        struct MATRIX3 m = *func_001A6318(p);
        struct SO *pso = p->pso;
        func_002333B4(pso, 0, 0x40);
        pso->m[0] = pso->m[5] = pso->m[10] = pso->m[15] = 1.0f;
        g_sw.cid++;
        p->pso->id = g_sw.cid;
        {
            struct VTE *e = &p->vt[18];
            ((void (*)(void *))e->pfn)((char *)p + e->delta);
        }
        {
            struct VTE *e = &p->vt[29];
            ((void (*)(void *, qword))e->pfn)((char *)p + e->delta, q);
        }
        {
            struct VTE *e = &p->vt[30];
            ((void (*)(void *, struct MATRIX3 *))e->pfn)((char *)p + e->delta, &m);
        }
    }
    func_00149A50(&g_sw, p, D_002A4D10, 0);
}
