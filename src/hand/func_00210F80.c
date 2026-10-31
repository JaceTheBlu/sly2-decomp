extern float D_003E1BFC;
extern struct CLOCK { float t; float dt; } g_clock;
extern char D_002A8AB0[];
void fiprintf(void *f, const char *fmt, ...);
void func_00210F80(void *f)
{
    float t = -g_clock.t + D_003E1BFC; int n; t = (t < 0.0f) ? 0.0f : t;
    n = (int)t;
    {
        int q = n / 60;
        fiprintf(f, D_002A8AB0, q, n - q * 60);
    }
}
