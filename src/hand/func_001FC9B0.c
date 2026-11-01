#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
struct LO {char pad28[0x28];unsigned long flags;};
struct RANGE {float low,high;};
struct E {struct LO *object;struct RANGE limits;float gain;};
struct P {char pad1C[0x1C];struct LO *object;qword position;char pad30[0x70];int counts[6];struct E entries[6][8];};
extern qword D_002A2DD0;
int func_0011D4D0(float,float,float);
void func_001FB528(struct P *);
qword func_001A62E8(struct LO *);
void func_001FB778(struct P *,qword,const struct RANGE *,float *,int *);
void func_001FC380(struct P *,int,int);
void func_001FC2E0(struct P *,int,float);
static inline int FNear(qword a, qword b)
{
    return func_0011D4D0(GetX(a), GetX(b), 0.0001f) && func_0011D4D0(GetY(a), GetY(b), 0.0001f) && func_0011D4D0(GetZ(a), GetZ(b), 0.0001f);
}
void func_001FC9B0(struct P *p)
{
    int group;
    if (p->object || !FNear(D_002A2DD0, p->position))
        func_001FB528(p);
    for (group = 0; group < 6; group++) {
        int count = p->counts[group];
        if (count) {
            float maximum = 0.0f;
            int flags = 0, active = 0, i;
            int *pflags = &flags;
            float fade;
            for (i = 0; i < count; i++) {
                struct E *entry = &p->entries[group][i];
                struct LO *object = entry->object;
                if (object && ((object->flags >> 60) & 1) == 1) {
                    active++;
                    func_001FB778(p, func_001A62E8(object), &entry->limits, &fade, pflags);
                    pflags = 0;
                    { float gain = fade * entry->gain; maximum = maximum > gain ? maximum : gain; }
                }
            }
            func_001FC380(p, group, active == 1 ? flags : 0);
            func_001FC2E0(p, group, maximum);
        }
    }
}
