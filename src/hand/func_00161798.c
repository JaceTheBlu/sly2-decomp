#include "cref.h"
extern int D_003E0FB0;
extern char D_003D4A60[];
void func_002581C0(CRef *pref, int a, void *b);
void func_00129EC8(CRef *pref);
int func_00161798(void)
{
    CRef ref;
    int n;
    func_002581C0(&ref, D_003E0FB0, D_003D4A60);
    n = ref.m_tag;
    func_00129EC8(&ref);
    return n;
}
