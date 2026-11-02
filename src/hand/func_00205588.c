extern char g_sndmgr[];
extern char g_sw[];
struct S { char pad[0x2A0]; int a[6]; };
int func_001FD0C0(void *p, int i);
void *PloFindSwObject__FP2SWi3OIDP2LO(void *p, int a, int b, struct S *ps);
void *func_001F03C8(void *x, struct S *ps);
void RetractSma__FP3SMA(void *y);
void func_00205588(struct S *p, int mask)
{
    int i;
    for (i = 0; i < 6; i++) {
        int f = (unsigned int)i < 6;
        int bit = 1 << i;
        if (!f) bit = 0;
        if (mask & bit) {
            if (p->a[i] != 0) {
                if (--p->a[i] <= 0) {
                    int id = func_001FD0C0(g_sndmgr, i);
                    void *x = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, id, p);
                    if (x) {
                        void *y = func_001F03C8(x, p);
                        if (y)
                            RetractSma__FP3SMA(y);
                    }
                }
            }
        }
    }
}
