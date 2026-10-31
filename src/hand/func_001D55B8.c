#include "cref.h"
extern int D_002C2D8C;
extern void *D_003E0FD8;
extern char D_003D4A60[];
void func_002581C0(CRef *pref, void *a, char *b);
void func_00129EC8(CRef *pref);
int func_001D55B8(void) {
    switch (D_002C2D8C) {
    case 2:
        return 1;
    case 0:
    case 3:
        return 0;
    case 1:
    default: {
        CRef ref;
        int n;
        func_002581C0(&ref, D_003E0FD8, D_003D4A60);
        n = ref.m_tag;
        func_00129EC8(&ref);
        return n ^ 1;
    }
    }
}
