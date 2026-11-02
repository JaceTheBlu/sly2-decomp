#include "clock.h"
extern struct CLOCK g_clock;
extern char g_sw[];
extern int D_002C0908[][5], D_002C0948[][5];
extern float D_002C0900;
struct P { char pad[0x150]; int x150; char pad1[0x1034 - 0x154]; int x1034; char pad2[0x1524 - 0x1038]; float f1524; float f1528; int x152C; int x1530; int x1534; };
struct P *func_001C4840(void *g);
int func_0020F0B0(void *g);
int GetSmaCur__FP3SMA(int a);
int func_001F07C8(int a);
int func_001C46C0(int a, int b, float f);
void func_001F0660(int a, int b);
void func_001B5820(struct P *p)
{
    int a;
    if (func_001C4840(g_sw) != p) return;
    if (func_0020F0B0(g_sw)) return;
    a = GetSmaCur__FP3SMA(p->x1034);
    if (a != func_001F07C8(p->x1034)) return;
    if (a >= 0x1D0) return;
    if (a < 0x1CB) return;
    p->f1524 -= g_clock.dt;
    if (func_001C46C0(p->x150, 0xF0, 0.0f)) {
        p->x152C--;
        p->f1528 = p->f1524;
    }
    if (p->f1524 <= 0.0f) {
        if (p->x152C <= 0) a = D_002C0908[p->x1534][a - 0x1CB];
        else a = D_002C0948[p->x1534][a - 0x1CB];
    } else if (p->f1528 - p->f1524 > D_002C0900) {
        a = 0x1CA;
    }
    if (p->x1530) func_001F0660(p->x1530, a);
    func_001F0660(p->x1034, a);
}
