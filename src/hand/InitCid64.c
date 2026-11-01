void InitCid56(void *p);
void InitCid64(char *p)
{
    InitCid56(p);
    *(int *)(p + 0x4A4) = 1;
}
