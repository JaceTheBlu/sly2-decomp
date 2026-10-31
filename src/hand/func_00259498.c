// SLY2_CC: tools/compilers/bundle/ee-gcc2.95.3-136
// SLY2_CFLAGS: -O2 -G0 -ffast-math -mvu0-use-vf0-vf31
typedef struct AREQ { int cb; int cbAlign; } AREQ;
int PvAllocSwClearImpl__FP7SWALLOC(AREQ *preq);
static inline int New(unsigned int cb) { AREQ req; req.cb = cb; req.cbAlign = 0x10; return PvAllocSwClearImpl__FP7SWALLOC(&req); }
typedef struct { char pad[0x10]; int x10; char pad2[0x1C]; int x30; } T;
typedef struct { char pad[0xE4]; T *xE4; } S;
T *func_002590F0(S *, int);
void func_00259498(S *p, int k)
{
    T *t;
    if (p->xE4->x10 == k) return;
    if (p->xE4->x10 != 0) return;
    t = func_002590F0(p, 1);
    t->x10 = k;
    switch (k) {
    case 1: t->x30 = New(0x20); break;
    case 2: t->x30 = -1; break;
    case 3: t->x30 = New(0x30); break;
    }
}
