#include "cref.h"
struct VTE { short d; short pad; void (*pfn)(); };
struct E { int id; int a, b; };
struct P { char pad[0xC]; struct VTE *vt; char pad2[0x1180 - 0x10]; struct E ae[3]; };
extern char D_002A4D50[];
extern char D_002A4D58[];
int sprintf(char *, const char *, ...);
void func_001D8A38(struct CRef *r, void *a, void *b, char *c, int d);
void func_00129EC8(struct CRef *r);
void func_00141EF8(struct P *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        char ach[16];
        struct CRef r;
        struct VTE *e;
        sprintf(ach, D_002A4D50, i);
        e = &p->vt[103];
        func_001D8A38(&r, ((void *(*)(void *))e->pfn)((char *)p + e->d), D_002A4D58, ach, 0);
        p->ae[i].id = r.m_tag;
        func_00129EC8(&r);
    }
    {
        struct VTE *e = &p->vt[105];
        ((void (*)(void *))e->pfn)((char *)p + e->d);
    }
}
