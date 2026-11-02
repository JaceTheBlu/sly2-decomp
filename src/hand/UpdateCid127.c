// Actor update: commit completed state after every noninitial guard path.
struct VT { char pad[0x190]; short d; short pd; void (*pf)(void *); };
struct S { char pad[0xC]; struct VT *pvt; char pad10[0x48]; int x58; float x5C; char pad60[0xB0]; int x110; int x114; };
extern struct G { char pad[0x3B0C]; void *x3B0C; } g_sw;
extern float D_002DDF0C;
extern int D_002DD318;
extern char D_002E6550[], D_003DA4F0[], D_002DFC00[];
int func_002121C8(struct S *p);
void UpdateCid128(struct S *p);
int func_001D9880(void *);
int PvAllocSwCopyImpl__FiPv(void *, int);
void func_0020F030(struct G *, int);
void func_00162DF8(void *);
void UpdateCid127(struct S *p)
{
    int r = func_002121C8(p);
    if (r)
        return;
    UpdateCid128(p);
    if (p->x58 == 2 && 0.5f < D_002DDF0C - p->x5C && !func_001D9880(D_002E6550)
        && !func_001D9880(D_003DA4F0) && PvAllocSwCopyImpl__FiPv(D_002DFC00, 0xF0)) {
        func_0020F030(&g_sw, 0);
        if (p->x114 == 0 && g_sw.x3B0C) {
            D_002DD318++;
            func_00162DF8(g_sw.x3B0C);
        }
        p->pvt->pf((char *)p + p->pvt->d);
    }
    p->x110 = 1;
    return;
}
