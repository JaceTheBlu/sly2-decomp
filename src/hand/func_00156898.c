typedef struct CLOCK { float t; float dt; } CLOCK;
extern CLOCK g_clock;
extern float D_002BDCE0;
extern float D_002BDCF0[3];
struct Q { char pad[0x54]; float g54; char pad2[8]; float g60; };
struct S { int pad[5]; struct Q *pq; char pad2[0x4C - 0x18]; float t4C; };
static inline float GMin(float a, float b) { return a < b ? a : b; }
float func_00156898(struct S *p)
{
    struct Q *pq = p->pq;
    float dt, t;
    if (0.0f < pq->g60) {
        dt = GMin(D_002BDCE0, pq->g60);
        t = GMin((g_clock.t - p->t4C) / dt, 1.0f);
        return pq->g54 * (D_002BDCF0[0] + t * (D_002BDCF0[1] + t * D_002BDCF0[2]));
    }
    return pq->g54;
}
