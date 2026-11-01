#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct Q { char pad[0x58]; int x; };
struct P { char pad[0x14]; struct Q *pq; char pad2[8]; qword v20; };
extern int func_0011D910(void *p, float z);
extern float func_00156898(struct P *p);
int func_00156918(struct P *p, qword pos)
{
    qword d, l;
    float dist;
    __asm__("vsub.xyzw %0, %1, %2" : "=j"(d) : "j"(pos), "j"(p->v20));
    if (!func_0011D910(&p->pq->x, GetZ(d)))
        return 0;
    __asm__("vmul.xy %0, %1, %1\n\tvaddy.x %0, %0, %0y" : "=&j"(l) : "j"(d));
    __asm__("vsqrt Q, %1x\n\tvwaitq\n\tvaddq.x %0, $vf0, Q" : "=j"(l) : "j"(l));
    __asm__("qmfc2.ni %0, %1" : "=r"(dist) : "j"(l));
    { int f = func_00156898(p) < dist; return f ^ 1; }
}
