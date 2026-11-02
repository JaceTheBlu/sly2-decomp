#include "cref.h"
struct CMD { char pad[0x10]; unsigned int c; int a[4]; };
void func_002013D8(struct CRef *pref, void *x, int a, int b, unsigned int *pc, int *pa);
struct CMD *func_001E01F8(void *pq, int kind, int b);
void func_001AE5A0(void *pdst, void *psrc, int cb);
void func_00129EC8(struct CRef *pref);
void func_001E0310(void *pq, void *x)
{
    int a[8];
    struct CRef ref;
    unsigned int c;
    struct CMD *p;
    func_002013D8(&ref, x, 6, 8, &c, a);
    p = func_001E01F8(pq, 3, 0);
    if (c > 4) c = 4;
    {
        unsigned int n = c;
        p->c = n;
        func_001AE5A0(&p->a, a, n * 4);
    }
    func_00129EC8(&ref);
}
