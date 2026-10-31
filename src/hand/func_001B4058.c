#include "clock.h"
extern struct CLOCK g_clock;
struct S { char pad[0x10C]; float f10C; int x110; int x114; char x118[8]; int x120; char pad2[0x5C]; char x180[0xBC]; int x23C; volatile int x240; };
int func_001B41D0(struct S *p, int n);
int func_0024B540(void *a, int b, int c);
void func_001B3510(struct S *p);
void func_001B3700(struct S *p);
void func_00234CA0(int n);
int func_00234A40(int n);
void Update__10CMpegAudio(void *p);
void func_001B4058(struct S *p)
{
    while (p->x240 == 1) func_001B41D0(p, 0);
    if (func_0024B540(p->x118, p->x110 + 0x285A80, 0x5CD) < 0) return;
    if (p->x120 == 0) {
        p->f10C = g_clock.tFrame;
        func_001B3510(p);
        func_001B3700(p);
        func_00234CA0(0);
    }
    while (p->x240) func_001B41D0(p, 0);
    func_00234A40(p->x23C);
    Update__10CMpegAudio(p->x180);
}
