void InitStepguard__FP9STEPGUARD(void *p);
void InitCid64(char *p)
{
    InitStepguard__FP9STEPGUARD(p);
    *(int *)(p + 0x4A4) = 1;
}
