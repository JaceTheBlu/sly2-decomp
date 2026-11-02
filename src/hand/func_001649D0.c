struct X { char pad[0x64]; void *f64; void *f68; };
struct G { char pad[0x3B0C]; struct X *f3b0c; };
extern struct G g_sw;
int func_0015E9C8(struct G *pg, int kind, int n, int m, int c, void **apv);
int func_00164030(void *p);
void func_00162908(struct X *p);
void func_001628B8(struct X *p);
void func_001649D0(void)
{
    struct X *apx[256];
    struct X *pxFound = 0;
    int c = func_0015E9C8(&g_sw, 5, 0x84, 0, 0x100, (void **)apx);
    int i;
    for (i = 0; i < c; i++) {
        struct X *px = apx[i];
        if (func_00164030(px->f64) && !func_00164030(px->f68))
            pxFound = px;
    }
    if (pxFound != g_sw.f3b0c) {
        if (g_sw.f3b0c)
            func_00162908(g_sw.f3b0c);
        if (pxFound)
            func_001628B8(pxFound);
    }
}
