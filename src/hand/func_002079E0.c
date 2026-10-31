#include "dl.h"
extern float D_002A8868;
extern struct DL D_003E1444;
struct S { char pad[0xFF8]; float t; };
void func_001F3EA8(struct S *p);
void func_0011A220(struct DL *pdl, void *pv);
void func_002079E0(struct S *p) { func_001F3EA8(p); func_0011A220(&D_003E1444, p); p->t = D_002A8868; }
