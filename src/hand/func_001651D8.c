struct G;
struct Q { char pad[0x10]; int f10; int f14; int f18; };
extern struct G g_sw;
extern struct Q D_002DEB30;
void *PloFindSwObject__FP2SWi3OIDP2LO(struct G *pg, int kind, int oid, void *owner);
void func_00165E10(struct G *pg, void *p);
void func_00165538(void *p);
void func_0022B490(struct G *pg, int n, int a, int b, int c, int d);
void func_001651D8(void *pv, int n, int oid)
{
    struct G *pg = &g_sw;
    void *p = PloFindSwObject__FP2SWi3OIDP2LO(pg, 0x105, oid, 0);
    if (p) {
        func_00165E10(pg, p);
        func_00165538(p);
    } else {
        D_002DEB30.f10 = -1;
        D_002DEB30.f14 = -1;
        D_002DEB30.f18 = oid;
        func_0022B490(pg, n, 0x189, -1, 8, -1);
    }
}
