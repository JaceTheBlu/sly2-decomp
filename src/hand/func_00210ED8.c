#include "cref.h"
extern char D_003D4A60[];
extern char D_002A8AA0[];
void func_002581C0(struct CRef *r, int *p, void *q);
void func_00129EC8(struct CRef *r);
void fiprintf(void *f, const char *fmt, ...);
void func_00210ED8(void *f, int **pp)
{
    int *p = *pp;
    if (p && *p) {
        char *fmt = D_002A8AA0;
        struct CRef r;
        int v;
        func_002581C0(&r, p, D_003D4A60);
        v = r.m_tag;
        func_00129EC8(&r);
        fiprintf(f, fmt, v);
    }
}
