void func_001EEF70(void *p);
void func_0014AE38(void *p, int n);
extern float g_clock;
void func_0014A200(char *p)
{
    func_001EEF70(p);
    func_0014AE38(p, 0);
    *(float *)(p + 0x48) = g_clock;
    *(int *)(*(char **)(p + 0x10) + 0x4A4) = 0;
}
