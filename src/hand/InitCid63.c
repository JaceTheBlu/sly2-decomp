void InitCid56(void *p);
extern void *D_002DD648;
void InitCid63(char *p)
{
    InitCid56(p);
    D_002DD648 = p;
    *(int *)(p + 0x4A4) = 1;
}
