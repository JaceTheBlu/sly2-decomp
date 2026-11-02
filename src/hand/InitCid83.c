void InitSo__FP2SO(void *p);
void func_00148718(void *p);
void InitCid83(char *p)
{
    unsigned int v;
    InitSo__FP2SO(p);
    func_00148718(p + 0x150);
    v = *(unsigned int *)(p + 0x40);
    if ((v ^ 1) & 1) *(int *)v |= 2;
    else *(unsigned int *)(p + 0x40) = v | 2;
}
