#include "clock.h"
struct S { char pad[0x2044]; void *p2044; };
extern struct CLOCK g_clock;
extern int D_003E1BEC;
void SetClockRate__FP5CLOCK3CRKf(struct CLOCK *pclock, int n, float g);
void func_001FB098(void *p, float g);
void func_00258040(void **pp, int n);
void func_00141E28(struct S *p, int n);
void func_0018DD78(struct S *p, int n)
{
    if (n == 0x1D || n == 0x2A) {
        void **pp;
        SetClockRate__FP5CLOCK3CRKf(&g_clock, 1, 1.0f);
        pp = &p->p2044;
        if (*pp) {
            func_001FB098(*pp, 0.0f);
            func_00258040(pp, 0);
        }
        D_003E1BEC = 0;
    } else {
        func_00141E28(p, n);
    }
}
