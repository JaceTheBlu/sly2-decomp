struct G { char pad[0x3B18]; int f3b18; char pad2[0x3C84 - 0x3B1C]; int f3c84; };
extern struct G g_sw;
int func_0020E040(struct G *p);
int SwitchToPo__FP2PO(void);
void func_0022B490(struct G *p, int n, int a, int b, int c, int d);
void func_00162E38(int n)
{
    struct G *pg = &g_sw;
    pg->f3b18 = n;
    if (!func_0020E040(pg) && !pg->f3c84)
        func_0022B490(pg, SwitchToPo__FP2PO(), 0x189, -1, 0, -1);
}
