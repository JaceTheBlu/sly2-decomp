void OnCid48Remove(void *p);
void func_001490A0(void *p, int n);
void func_001492B0(char *p)
{
    OnCid48Remove(p);
    if ((unsigned int)(*(int *)(p + 0x1E0) - 1) < 2) {
        func_001490A0(p, 0);
    }
}
