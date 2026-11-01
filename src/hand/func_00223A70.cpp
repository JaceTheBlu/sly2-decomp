#include "vu0.h"
/* MATCH: the loop's func_0011E1A0 result is a plain qword local; gcc emits the qmtc2 itself and schedules it. */
// Complete camera segment avoidance WIP. FRAME has no instance members.
typedef int qword __attribute__((mode(TI)));
union V {qword q;float f[4];};
struct O;
struct SO;
struct N;
struct S {O *object;char pad[0x30];int state;};
struct CAMERA {char pad[0x48];float radius;};
struct WORLD;
extern CAMERA g_cm;
extern WORLD g_sw;
extern float D_002A9700;
extern "C" {
void *func_001AE478(void *);
void _$_18CBinaryInputStream(void *,int);
qword func_001A62E8(void *);
int func_0014F030(void *,SO *);
void func_0020FAA0(WORLD *,qword,qword,int (*)(void *,SO *),void *,int *,SO ***);
qword func_0014EB70(int,SO **,qword,float);
int func_0014EA08(int count,SO **objects,qword origin,qword endpoint,float gap,float *low,float *high);
float func_00223A10(void *,qword,qword,N *);
qword func_0014EDA0(CAMERA *,int,SO **,float (*)(void *,qword,qword,N *),qword,qword,float,float);
void DecomposeCylind__FUxPfN21(qword,float *,float *,float *);
qword func_0011E1A0(float,float,float);
}
struct MARK {MARK(){(void)func_001AE478(this);}~MARK(){_$_18CBinaryInputStream(this,2);}};
struct WORK {V minimum,maximum,origin,candidate;MARK mark;V offset,rayEnd,best,scalar;int count;SO **objects;float low,high,phase,radius,height;};
static inline qword Sub(qword a,qword b){__asm__("vsub.xyzw %0,%0,%1":"+j"(a):"j"(b));return a;}
static inline qword ScalarHome(V &home,float value){home.q=QwFromG(value);return home.q;}
static inline qword Blend(qword a,qword b,qword left,qword right){__asm__("vmulax.xyzw ACC,%0,%2x\n\tvmaddx.xyzw %0,%1,%3x":"+j"(a):"j"(b),"j"(left),"j"(right));return a;}
static inline qword BlendToRight(qword a,qword b,qword left,qword right){__asm__("vmulax.xyzw ACC,%1,%2x\n\tvmaddx.xyzw %0,%0,%3x":"+j"(b):"j"(a),"j"(left),"j"(right));return b;}
static inline void StoreVF(qword *p,qword q){__asm__("sqc2 %1,%0":"=m"(*p):"j"(q));}
extern "C" void func_00223A70(S *p,qword begin,qword end,qword *out){
    O *object=p->object;
    WORK w;
    qword final;
    float initialAngle=0.0f;
    float one=1.0f;
    w.minimum.q=QwMin(begin,QwMin(end,func_001A62E8(object)));
    w.maximum.q=QwMax(begin,QwMax(end,func_001A62E8(object)));
    func_0020FAA0(&g_sw,w.minimum.q,w.maximum.q,func_0014F030,0,&w.count,&w.objects);
    int count=w.count; SO **objects=w.objects;
    w.origin.q=func_0014EB70(count,objects,func_001A62E8(object),500.0f);
    func_0014EA08(w.count,w.objects,w.origin.q,end,initialAngle,&w.low,&w.high);
    if(w.high<one){
        float angle=initialAngle;
        p->state=4;
        DecomposeCylind__FUxPfN21(Sub(end,begin),&w.phase,&w.radius,&w.height);
        float bestCost=D_002A9700;
        float minGap=initialAngle;
        do{
            qword off=func_0011E1A0(w.phase+angle,w.radius,w.height);
            w.offset.q=off;
            w.rayEnd.q=QwAdd(begin,off);
            func_0014EA08(w.count,w.objects,w.origin.q,w.rayEnd.q,minGap,&w.low,&w.high);
            float cost=(1.25f-w.high)*(GAbs(angle)+0.47123894f);
            if(cost<bestCost){
                float left=1.0f-w.high;
                bestCost=cost;
                qword a=ScalarHome(w.scalar,left);
                qword right=ScalarHome(w.scalar,w.high);
                w.best.q=Blend(w.origin.q,w.rayEnd.q,a,right);
            }
            float next=-angle;
            if(angle<=minGap)next+=0.28559935f;
            angle=next;
            if(bestCost<(GAbs(next)+0.47123894f)*0.25f)break;
        }while(angle<3.1415927f);
        w.candidate.q=w.best.q;
    }else w.candidate.q=end;
    final=QwToVf(func_0014EDA0(&g_cm,w.count,w.objects,func_00223A10,w.candidate.q,w.candidate.q,g_cm.radius,g_cm.radius));
    func_0014EA08(w.count,w.objects,w.candidate.q,final,0.0f,&w.low,&w.high);
    if(w.high!=1.0f){
        float u=(w.low+w.high)*0.5f;
        qword left=ScalarHome(w.offset,1.0f-u);
        qword right=ScalarHome(w.offset,u);
        final=BlendToRight(w.candidate.q,final,left,right);
    }
    StoreVF(out,final);
}
