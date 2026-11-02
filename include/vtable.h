/* One entry of a g++ 2.95 vtable (old ABI): `this` adjustment, unused index, function.  A virtual call is
   ((ret (*)(void *, ...))e->pfn)((char *)obj + e->delta, ...).  Class vtables: docs/CLASSES.md. */
#ifndef VTABLE_H
#define VTABLE_H

struct VTE
{
    short delta;        /* added to `this` before the call */
    short index;        /* unused by the game */
    void *pfn;
};

#ifndef __cplusplus
typedef struct VTE VTE;
#endif

#endif /* VTABLE_H */
