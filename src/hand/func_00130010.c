struct VTE { short d; short pad; int (*pfn)(); };
struct O { int pad[3]; struct VTE *vt; };
struct A { int f0; int f4; };
extern char g_sw[];
struct O *PloFindSwObject__FP2SWi3OIDP2LO(void *, int, int, void *);
void func_00130010(void *p, void *q, struct A *pa, struct O **ppo, int *pn) {
    if (q) *ppo = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 1, pa->f4, q);
    else *ppo = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pa->f4, p);
    if (!*ppo) *pn = 0;
    else { struct O *po = *ppo; *pn = ((int (*)(void *, int))po->vt[43].pfn)((char *)po + po->vt[43].d, pa->f0); }
}
