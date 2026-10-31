typedef int qword __attribute__((mode(TI)));
typedef struct CLOCK { float t; float dt; } CLOCK;
extern CLOCK g_clock;
typedef struct Q { char pad[0x30]; qword a; char pad2[0x68]; float t; char pad3[4]; qword b; } Q;
typedef struct P { char pad[8]; Q *pq; char pad2[0x14]; qword v20; qword v30; } P;
void func_00117120(float tMax, float t, float s, qword a, qword va, qword b, qword vb, qword *ppos, qword *pv, int n);
void func_0012E060(P *p, qword *pa, qword *pb, float t)
{
    float g = g_clock.t;
    Q *pq = p->pq;
    if (pq->t <= g + t) {
        if (pa) *pa = p->v20;
        if (pb) *pb = p->v30;
    } else {
        func_00117120(pq->t - g, t, 1.0f, pq->a, pq->b, p->v20, p->v30, pa, pb, 0);
    }
}
