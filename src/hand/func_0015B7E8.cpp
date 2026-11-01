#include "vu0.h"
// MATCH from the 4-diff wip: ONE register pin, the pb->apos base in $2 (v0) inside the pxf block.
// NEAR MISS (round 9): 4/130, only $v0/$v1 for &apos[i] in the first pxf block
typedef int qword __attribute__((mode(TI)));
struct AL { int cb; int cbAlign; AL(int c, int a) { cb = c; cbAlign = a; } };
struct MATRIX3 { qword r[3]; };
struct XF { qword pos; MATRIX3 mat; qword v; qword w; };
struct EMITVX { int c; float dTilt; float dPan; float tiltBase; float panBase; };
struct EMITTER { char pad[0x1C]; XF *pxf; char pad1[0x84 - 0x20]; int x84; char pad2[0x90 - 0x88]; char x90[1]; };
struct BUF { qword *apos; qword *av; float *ag; float *an; int f10; };
extern "C" {
void *PvAllocStackImpl__FP7SWALLOC(AL *pal);
void func_0015AE38(int n, void *p, int c, EMITVX *pvx);
void func_0015A808(EMITTER *pemit, int i, int c, qword *ppos, qword *pnormal);
void func_0015B0C8(void *p, EMITVX *pvx, void *q, int n, qword *ppos, qword *pnormal, qword *pvel, float *ptBirth, float *ptDeath);
void func_0015AD48(EMITTER *pemit, qword *ppos, qword *pvel);
void func_0015B7E8(int c, EMITTER *pemit, BUF *pb);
}
static inline void *PvAlloc(int cb, int cbAlign) { AL al(cb, cbAlign); return PvAllocStackImpl__FP7SWALLOC(&al); }
static inline qword MulRow(const MATRIX3 &m, qword v)
{
    qword r;
    __asm__("vmulax.xyz ACC, %2, %1x\n\tvmadday.xyz ACC, %3, %1y\n\tvmaddz.xyz %0, %4, %1z" : "=j"(r) : "j"(v), "j"(m.r[0]), "j"(m.r[1]), "j"(m.r[2]));
    return r;
}
static inline qword Cross(qword a, qword b)
{
    qword d;
    __asm__("vopmula.xyz ACC, %1, %2\n\tvopmsub.xyz %0, %2, %1" : "=j"(d) : "j"(a), "j"(b));
    return d;
}
void func_0015B7E8(int c, EMITTER *pemit, BUF *pb)
{
    pb->apos = (qword *)PvAlloc(c * 16, 16);
    pb->av = (qword *)PvAlloc(c * 16, 16);
    pb->ag = (float *)PvAlloc(c * 4, 16);
    pb->an = (float *)PvAlloc(c * 4, 16);
    EMITVX vx;
    func_0015AE38(pemit->x84, pemit->x90, c, &vx);
    for (int i = 0; i < c; i++) {
        union { qword q; float f[4]; } normal;
        func_0015A808(pemit, i, c, &pb->apos[i], &normal.q);
        func_0015B0C8((char *)pemit + 0x50, &vx, (char *)pemit + 0x10, i, &pb->apos[i], &normal.q, &pb->av[i], &pb->ag[i], &pb->an[i]);
        XF *pxf = pemit->pxf;
        if (pxf) {
            {
                register qword *ppos __asm__("$2"); // register pin (target loads pb->apos into v0 and forms &apos[i] there)
                ppos = pb->apos;
                ppos[i] = QwAdd(MulRow(pxf->mat, ppos[i]), pxf->pos);
            }
            qword d = QwSub(pb->apos[i], pxf->pos);
            qword x = Cross(pxf->w, d);
            qword t = QwAdd(MulRow(pxf->mat, pb->av[i]), pxf->v);
            pb->av[i] = QwAdd(t, x);
        }
        if (pb->f10)
            func_0015AD48(pemit, &pb->apos[i], &pb->av[i]);
    }
}
