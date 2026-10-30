struct VTE { short d; short p; void (*pfn)(void *); };
struct X { char pad[0xC]; struct VTE *pvt; };
struct G { char pad[0x200]; struct X *r200; int n204; struct X *a208[8]; struct X *r228; };
extern struct G g_sndmgr;
extern int D_002DD2E0, D_002DD2E4, D_002DD2E8, D_002DD2EC, D_002DD2F0, D_002DD2F4;
extern char D_004520A8[], D_004520D0[], D_004520F8[], D_00452120[], D_00452148[], D_00452170[];
void func_001FCD38(struct G *);
void func_0011CCA8(void *, int, int, int);
void func_00258348(struct G *, int);
static inline void Release(struct X **pp)
{
    struct X *px = *pp;
    if (px) px->pvt[2].pfn((char *)px + px->pvt[2].d);
}
void func_001FF188(int init, int prio)
{
    if (prio != 0xFFFF) return;
    if (init) {
        func_001FCD38(&g_sndmgr);
        if (++D_002DD2E0 == 1) func_0011CCA8(D_004520A8, 0x14, 0x2000, 0x10);
        if (++D_002DD2E4 == 1) func_0011CCA8(D_004520D0, 0x18, 0x800, 0x10);
        if (++D_002DD2E8 == 1) func_0011CCA8(D_004520F8, 0x28, 0x200, 0x10);
        if (++D_002DD2EC == 1) func_0011CCA8(D_00452120, 0x1C, 0x800, 0x10);
        if (++D_002DD2F0 == 1) func_0011CCA8(D_00452148, 0xC, 0xC8, 0x10);
        if (++D_002DD2F4 == 1) func_0011CCA8(D_00452170, 0x14, 0x100, 0x10);
    } else {
        struct G *pg = &g_sndmgr;
        struct X **pe = &pg->r228;
        struct X **pa;
        Release(pe);
        pa = pg->a208;
        if (pa) {
            struct X **e = pa + 8;
            while (pa != e) {
                --e;
                Release(e);
            }
        }
        Release(&pg->r200);
        func_00258348(pg, 2);
    }
}
