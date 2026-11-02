typedef int qword __attribute__((mode(TI)));
struct M { qword r[4]; };
struct T { float t; float g; char pad[8]; struct M m; };
struct VT { char pad[0xF8]; short d; short pd; struct M *(*matrix)(void *); };
struct S { char pad[0xC]; struct VT *vt; char pad10[0x148]; int count; struct T *array; int index; int idle; };
extern struct CLOCK { float t; float dt; } g_clock;
static inline int Wrap(int index, int count)
{
    return index % count;
}
void func_0021BC08(struct S *p)
{
    float t = g_clock.t;
    struct M m = *p->vt->matrix((char *)p + p->vt->d);
    int n = p->count;
    int i = n + Wrap(0, n);
    t -= i * 0.016666668f;
    for (i--; i >= 0; i--) {
        struct T *e = &p->array[p->index];
        p->index = (p->index + 1) % p->count;
        e->t = t;
        e->g = 0.0f;
        t += 0.016666668f;
        e->m = m;
    }
    p->idle = 0;
}
