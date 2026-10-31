struct D { int a; int ib; };
extern char g_sw[];
int PloFindSwObject__FP2SWi3OIDP2LO(void *, int, int, void *);
void func_0013E590(char *p, struct D *pd) {
    *(int *)(p + pd->ib) = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pd->a, p);
}
