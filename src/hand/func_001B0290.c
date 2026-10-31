typedef struct M { int id; int a[7]; } M;
typedef struct MENU { char pad[0x20]; int x20; } MENU;
typedef struct G { char pad[0x3B0C]; int x3B0C; } G;
typedef struct H { char pad[0x24]; int x24; } H;
typedef struct X { char pad[0x1C]; int x1C; } X;
extern MENU D_003D9ED0;
extern G g_sw;
extern H D_003DA3C0;
extern char D_002E6550[];
extern M D_002C00E8[];
extern M D_002F65D0[];
extern char D_002BFD38[];
int func_0020E040(G *g);
int func_001D9880(void *p);
char *func_001C4840(G *g);
int FIsBasicDerivedFrom__FP5BASIC3CID(void *p, int k);
void func_0019CD38(void *p, int k);
int func_002127C8(void);
int _IppoFindPo__FP2PO(void);
int func_00132EA0(void *p);
void func_001AF4D8(MENU *pm, int c, M *am, int x, void *p);

int func_001B0290(X *px)
{
    char *pl;
    M *psrc, *pdst;
    unsigned int i;
    int f, k;

    if (!D_003D9ED0.x20) return 0;
    if (func_0020E040(&g_sw)) return 0;
    if (func_001D9880(D_002E6550)) return 0;
    pl = func_001C4840(&g_sw);
    if (pl && FIsBasicDerivedFrom__FP5BASIC3CID(pl, 0x34)) func_0019CD38(pl + 0xF00, -1);
    if (!func_002127C8()) return 0;
    psrc = D_002C00E8;
    pdst = D_002F65D0;
    for (i = 0; i < 7; i++) {
        f = 1;
        switch (psrc->id) {
        case 0x6A:
            f = 0;
            if (D_003DA3C0.x24) {
                if (_IppoFindPo__FP2PO()) f = 1;
            }
            break;
        case 0x6B:
            f = 0;
            if (g_sw.x3B0C) {
                if (_IppoFindPo__FP2PO()) f = 1;
            }
            break;
        case 0x43:
            f = 0;
            if (pl) {
                k = func_00132EA0(pl);
                if (k < 0x38) {
                    if (k >= 0x35) f = 1;
                }
            }
            break;
        case 0x2C:
            break;
        case 0x42:
            f = _IppoFindPo__FP2PO() != 0;
            break;
        }
        if (f) {
            *pdst = *psrc;
            pdst++;
        }
        psrc++;
    }
    func_001AF4D8(&D_003D9ED0, pdst - D_002F65D0, D_002F65D0, D_003D9ED0.x20, D_002BFD38);
    if (px) px->x1C |= 2;
    return 1;
}
