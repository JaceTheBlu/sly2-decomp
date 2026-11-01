void InitCid48(void *p);
void func_001A6CA8(void *p, int n);
void func_001471C0(char *p)
{
    unsigned int v;
    InitCid48(p);
    *(int *)(p + 0x150) = -1;
    func_001A6CA8(p, 1);
    v = *(unsigned int *)(p + 0x40);
    if ((v ^ 1) & 1) *(int *)v |= 0x102;
    else *(unsigned int *)(p + 0x40) = v | 0x102;
}
