extern struct { float t; float dt; } g_clock;
extern float D_002C3D40[3];
struct S { char pad[0xFBC]; int k; float t; };
void func_00207030(struct S *p, int n);
void func_00207288(struct S *p)
{
    switch (p->k) {
    case 8:
    case 13:
        if (g_clock.t - p->t > D_002C3D40[0])
            func_00207030(p, -1);
        break;
    case 34:
    case 37:
        if (g_clock.t - p->t > D_002C3D40[1])
            func_00207030(p, -1);
        break;
    case 21:
        if (g_clock.t - p->t > D_002C3D40[2])
            func_00207030(p, -1);
        break;
    }
}
