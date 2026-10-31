#include "cref.h"
void func_001D8A38(struct CRef *r, char *s, int a);
void func_00129EC8(struct CRef *r);
extern char D_002A8A78[];
int func_00210B28(void)
{
    struct CRef r;
    int v;
    func_001D8A38(&r, D_002A8A78, 0);
    v = r.m_tag;
    func_00129EC8(&r);
    return v;
}
