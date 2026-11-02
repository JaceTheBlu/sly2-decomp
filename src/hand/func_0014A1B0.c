void func_001EEF68(void *p);
void func_001FEE90(void *p);
void func_00209890(void *p, int n);
extern char g_sndmgr[];
void func_0014A1B0(char *p)
{
    func_001EEF68(p);
    func_001FEE90(g_sndmgr);
    func_00209890(*(void **)(p + 0x10), 0x24);
    *(int *)(p + 0x30) = -1;
    *(int *)(p + 0x40) = -1;
    *(int *)(p + 0x3C) = -1;
}
