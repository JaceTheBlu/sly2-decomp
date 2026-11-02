#include "vu0.h"
typedef struct { int n; int a; } ENT;
typedef struct {
    char pad[0x48];
    int c;
    ENT ae[64];
    int i;
    int first;
    int x254;
    int x258;
} OBJ;
extern int D_003DA570;
extern int D_002C35B4;
int func_001DBBA0(OBJ *);
void func_001DA9E8(OBJ *);
static inline int Clamp(int n, int lo, int hi)
{
    if (n < lo)
        return lo;
    if (n > hi)
        return hi;
    return n;
}
void func_001DBBE0(OBJ *p, int i)
{
    if (p->c == 0) {
        p->first = 0;
        p->i = -1;
        p->x254 = -1;
        p->x258 = -1;
    } else {
        i = Clamp(i, 0, p->c - 1);
        p->i = i;
        if (D_003DA570) {
            if (i < p->first) {
                p->first = i;
            } else {
                while (func_001DBBA0(p) - 1 < p->i)
                    p->first++;
            }
            if (p->first == 1)
                p->first = 0;
        } else {
            int n = Clamp(p->first, NMax(i - D_002C35B4 + 1, 0), i);
            p->first = n;
        }
        p->x254 = p->ae[p->i].n;
        p->x258 = p->ae[p->i].n;
    }
    func_001DA9E8(p);
}
