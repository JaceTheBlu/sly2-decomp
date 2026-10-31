#include "dl.h"
typedef unsigned long ulong;
extern struct DL D_003DD4BC;
int func_0011A380(struct DL *pdl, void *pv);
struct S { char pad[0x14]; void *x14; char pad2[0x10]; ulong fl; };
int func_001A61A0(struct S *p)
{
    int r = 0;
    if ((int)(p->fl >> 60) & 1) r = func_0011A380(&D_003DD4BC, p->x14) != 0;
    return r;
}
