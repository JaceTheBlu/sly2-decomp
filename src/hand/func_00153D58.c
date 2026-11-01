void InitAlo__FP3ALO(void *p);
void func_001A6CA8(void *p, int n);
void func_00153D58(char *p)
{
    unsigned int v;
    InitAlo__FP3ALO(p);
    func_001A6CA8(p, 1);
    v = *(unsigned int *)(p + 0x40);
    if ((v ^ 1) & 1) *(int *)v |= 2;
    else *(unsigned int *)(p + 0x40) = v | 2;
}
