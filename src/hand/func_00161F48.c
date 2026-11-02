struct E { int oid; int n; };
extern char g_sw[];
void *PloFindSwObject__FP2SWi3OIDP2LO(void *pg, int kind, int oid, void *owner);
void func_00164640(void *p, int n, void *owner);
void func_00161F48(void *pv, int c, struct E *ae, void *owner)
{
    int i;
    for (i = 0; i < c; i++) {
        void *p = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 0x105, ae[i].oid, owner);
        if (p)
            func_00164640(p, ae[i].n, owner);
    }
}
