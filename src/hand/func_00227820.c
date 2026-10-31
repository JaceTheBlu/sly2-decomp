#include "clock.h"
struct P { int id; };
struct Q { void *p0; };
extern struct CLOCK g_clock;
extern char g_sndmgr[];
extern char D_002A97F0[];
float func_001FCFD0(void *p, int id);
int func_00215E30(struct Q *q);
int func_001FE848(void *p, int id);
float func_001FE888(void *p);
void func_00215E80(struct Q *q, int n);
void func_0021EDA0(void *p, void *s);
void func_00227820(struct P *p, struct Q *q)
{
    void *pv;
    float f;
    int c, n, fShow;
    if (p->id == -1) return;
    pv = g_sndmgr;
    f = func_001FCFD0(pv, p->id) - 0.5f;
    c = func_00215E30(q);
    if (f <= 0.0f || !func_001FE848(pv, p->id))
        n = c;
    else
        n = (int)(func_001FE888(pv) / f * (float)c);
    if (n < c) {
        func_00215E80(q, n);
        fShow = 1;
    } else {
        fShow = (int)(g_clock.t * 4.0f) & 1;
    }
    if (fShow) func_0021EDA0(q->p0, D_002A97F0);
}
