struct E { int a, b, c, d; int pad[4]; };
extern struct E D_002BCD00[];
extern float g_clock;
int func_001441A0(void *p);
void func_001441C0(void *p, int a);
void func_00141CD0(char *p, int i)
{
    if (i != -1) func_001441C0(p, func_001441A0(p) - D_002BCD00[i].d);
    *(float *)(p + 0x1304) = g_clock;
}
