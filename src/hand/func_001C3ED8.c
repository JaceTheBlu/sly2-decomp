struct VTE { short d; short pad; void (*pf)(); };
struct LO { char pad[0xC]; struct VTE *vt; char p1[0x150 - 0x10]; void *x150; };
struct G { char pad[0x3EB8]; int c; struct LO *a[16]; char p1[0x3EFC - 0x3EFC]; struct LO *plo3EFC; };
extern struct G g_sw;
int func_001C4080(struct LO *p);
void *func_001AE4F8(int cb);
void *func_001C4280(void *pv, struct LO *p);
void func_001C4940(struct G *pg, struct LO *plo);
void func_001C4640(void *pv, int n);
void func_001C3ED8(struct LO *p, int n)
{
    if (n == func_001C4080(p)) return;
    if (!p->x150) {
        struct G *pg = &g_sw;
        if ((unsigned int)pg->c >= 16) return;
        pg->a[pg->c++] = p;
        p->x150 = func_001C4280(func_001AE4F8(0xE0), p);
    }
    switch (n) {
    case 1: {
        struct G *pg = &g_sw;
        struct LO *plo = pg->plo3EFC;
        if (p != plo) {
            if (plo) ((void (*)(void *, int))plo->vt[79].pf)((char *)plo + plo->vt[79].d, 0);
            func_001C4940(pg, p);
        }
        break;
    }
    case -1:
    case 0: {
        struct G *pg = &g_sw;
        if (p == pg->plo3EFC) func_001C4940(pg, 0);
        break;
    }
    }
    func_001C4640(p->x150, n);
}
