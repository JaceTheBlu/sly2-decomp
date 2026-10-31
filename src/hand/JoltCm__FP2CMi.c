extern float g_clock;
void JoltCm__FP2CMi(char *p, int a)
{
    *(float *)(p + 0x618) = g_clock;
    *(int *)(p + 0x61C) = a;
}
