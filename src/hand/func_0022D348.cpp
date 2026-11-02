#include "mat.h"
#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
union V {qword q;float f[4];};
struct JOB {int kind;void *owner;};
union SOURCE {void *object;float deadline;};
struct O {MATRIX4 local,world;float t0,t1;float *time,*dt;JOB *hook;int kind;short mode,state;unsigned int tag;O *parent;int priority;SOURCE source;unsigned short force,damping;qword velocity,v0,v1,v2,v3;};
extern qword D_002A2DD0;
extern "C" {
MATRIX4 func_0011C318(const MATRIX4 *);
MATRIX4 func_0022CDC0(O *);
void func_0022DD00(void *,O *);
void func_00117120(float,float,float,qword,qword,qword,qword,qword *,qword *,qword *);
}
static inline qword Zero() {qword r;__asm__("vsub.xyzw %0,$vf0,$vf0":"=j"(r));return r;}
static inline qword Transform(const MATRIX4 &m,qword v) {qword r=m.r[0];
    __asm__("vmulax.xyz ACC,%0,%4x\n\tvmadday.xyz ACC,%1,%4y\n\tvmaddaz.xyz ACC,%2,%4z\n\tvmaddw.xyz %0,%3,$vf0w":"+j"(r):"j"(m.r[1]),"j"(m.r[2]),"j"(m.r[3]),"j"(v));return r;}
static inline qword InverseTransform(const MATRIX4 &m,qword v) {register qword r __asm__("vf4")=m.r[0];
    __asm__("vmulax.xyz ACC,%0,%4x\n\tvmadday.xyz ACC,%1,%4y\n\tvmaddaz.xyz ACC,%2,%4z\n\tvmaddw.xyz %0,%3,$vf0w":"+j"(r):"j"(m.r[1]),"j"(m.r[2]),"j"(m.r[3]),"j"(v));return r;}
static inline qword BasisRow1(const MATRIX4 *m){register qword r __asm__("vf1");__asm__("lqc2 %0,16(%1)":"=j"(r):"r"(m),"m"(m->r[1]));return r;}
static inline qword BasisRow2(const MATRIX4 *m){qword r;__asm__("lqc2 %0,32(%1)":"=j"(r):"r"(m),"m"(m->r[2]));return r;}
static inline qword RotatePointerRows(const MATRIX4 &m,qword v){
qword r1=BasisRow1(&m);
qword r2=BasisRow2(&m);
__asm__("vmulax.xyz ACC,%1,%0x\n\tvmadday.xyz ACC,%2,%0y\n\tvmaddz.xyz %0,%3,%0z":"+j"(v):"j"(m.r[0]),"j"(r1),"j"(r2));return v;}
static inline qword Rotate(const MATRIX4 &m,qword v) {
    __asm__("vmulax.xyz ACC,%1,%0x\n\tvmadday.xyz ACC,%2,%0y\n\tvmaddz.xyz %0,%3,%0z":"+j"(v):"j"(m.r[0]),"j"(m.r[1]),"j"(m.r[2]));return v;}
static inline qword ParentRotate(const MATRIX4 &m,qword v) {register qword row0 __asm__("vf6")=m.r[0];
    __asm__("vmulax.xyz ACC,%1,%0x\n\tvmadday.xyz ACC,%2,%0y\n\tvmaddz.xyz %0,%3,%0z":"+j"(v):"j"(row0),"j"(m.r[1]),"j"(m.r[2]));return v;}
static inline qword RotateRow(const MATRIX4 &m,qword v) {qword r=m.r[0];
    __asm__("vmulax.xyz ACC,%0,%3x\n\tvmadday.xyz ACC,%1,%3y\n\tvmaddz.xyz %0,%2,%3z":"+j"(r):"j"(m.r[1]),"j"(m.r[2]),"j"(v));return r;}
static inline void Eval(O *p,qword *v) {func_00117120(p->t1-p->t0,*p->time-p->t0,*p->dt,p->v0,p->v1,p->v2,p->v3,0,v,0);}
extern "C" qword func_0022D348(O *p,O *stop,qword in) {
    qword sum;
    qword delta;
    MATRIX4 m;
    qword input=in;
    sum=Zero();
    for(;p!=stop;p=p->parent) {
        switch(p->mode) {
        case 0:case 3:case 10:case 12:case 15:case 19:break;
        default:
            switch(p->kind) {
            case 1:case 4:case 5:case 9:case 10: {
                switch(p->mode) {
                case 1:case 2:case 7:case 8:case 9:case 11:case 17:case 18:case 20:case 21:delta=p->velocity;break;
                case 5:case 6:
                    if(p->hook)func_0022DD00(p->hook->owner,p);
                    switch(p->state) {
                    case 3:case 4:delta=p->v1;break;
                    case 1:{V tmp;Eval(p,&tmp.q);delta=tmp.q;break;}
                    case 0:case 2:case 5:default:delta=D_002A2DD0;break;
                    }
                    break;
                }
                if(p->parent)sum=QwAdd(sum,RotateRow(p->parent->world,delta));
                else sum=QwAdd(sum,delta);
                break;
            }
            default: {
                if(p->hook)func_0022DD00(p->hook->owner,p);
                m=func_0022CDC0(p);
                O *parent=p->parent;
                if(parent) {
                    MATRIX4 inverse=func_0011C318(&p->world);
                    sum=QwAdd(sum,ParentRotate(parent->world,Transform(m,InverseTransform(inverse,input))));
                } else {
                    MATRIX4 inverse=func_0011C318(&p->world);
                    sum=QwAdd(sum,Transform(m,InverseTransform(inverse,input)));
                }
                break;
            }
            }
            break;
        }
    }
    if(stop) {MATRIX4 inverse=func_0011C318(&stop->world);sum=RotatePointerRows(inverse,sum);}
    return sum;
}
