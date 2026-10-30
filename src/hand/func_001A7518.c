extern int D_002E2050, D_002E2054;
extern void *D_002DD644;
extern int D_002BE538;
extern char g_sw[], D_003D9E70[], D_002DFC00[], g_cm[], D_002DDED0[];
void func_0023B7D8(void);
void func_001A7970(void);
void func_001613A8(void);
void func_0020E890(void *);
void func_001871C0(void *);
void func_0014BA38(void);
void func_0014D470(void *);
void func_0014D0B8(void *, int);
void func_00226550(void *);
void func_001D9648(void *);
void func_00160828(void);
int func_001477B0(void *);
void func_001CDA80(void *);
void func_00157FA0(void *);
void func_001D9820(void *);
void func_001477D8(void *);
void func_00160A98(void);
void func_001A7518(int a, int b)
{
    func_0023B7D8();
    D_002E2050 = a;
    D_002E2054 = b;
    func_001A7970();
    func_001613A8();
    for (;;) {
        func_0020E890(g_sw);
        func_001871C0(D_002DFC00);
        func_0014BA38();
        func_0014D470(g_cm);
        func_0014D0B8(D_002DDED0, 0);
        func_00226550(g_sw);
        func_001D9648(D_003D9E70);
        func_00160828();
        if (!D_002DD644 || func_001477B0(D_002DD644)) {
            func_001CDA80(g_sw);
            func_00157FA0(g_sw);
            func_001D9820(D_003D9E70);
        }
        if (D_002DD644)
            func_001477D8(D_002DD644);
        func_00160A98();
        D_002BE538++;
    }
}
