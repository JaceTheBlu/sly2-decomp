extern struct { float t; float dt; } g_clock;
struct C { virtual void f(); };
typedef void (C::*PMF)(void *);
struct D { char pad[0x60]; PMF pmf; };
struct OBJ {
    char pad0[0x14];
    float x14;
    float x18;
    char pad1c[0xF0 - 0x1C];
    D *xF0;
    C *xF4;
    void *xF8;
};
extern "C" void func_001CE980(OBJ *);
extern "C" void func_001D0800(OBJ *p)
{
    if (p->x18 < g_clock.t - p->x14) {
        PMF pmf = p->xF0->pmf;
        (p->xF4->*pmf)(p->xF8);
        func_001CE980(p);
    }
}
