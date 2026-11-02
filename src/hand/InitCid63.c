void InitStepguard__FP9STEPGUARD(void *p);
extern void *D_002DD648;
void InitCid63(char *p)
{
    InitStepguard__FP9STEPGUARD(p);
    D_002DD648 = p;
    *(int *)(p + 0x4A4) = 1;
}
