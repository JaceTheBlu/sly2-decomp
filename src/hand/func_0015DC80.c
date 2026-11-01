void InitLo__FP2LO(void *p);
void func_001A6CA8(void *p, int n);
void func_0015DC80(char *p)
{
    unsigned int v;
    InitLo__FP2LO(p);
    func_001A6CA8(p, 1);
    v = *(unsigned int *)(p + 0x40);
    if ((v ^ 1) & 1) *(int *)v |= 0xA;
    else *(unsigned int *)(p + 0x40) = v | 0xA;
}
