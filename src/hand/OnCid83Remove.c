void OnSoRemove__FP2SO(void *p);
void func_001490A0(void *p, int n);
void OnCid83Remove(char *p)
{
    OnSoRemove__FP2SO(p);
    if ((unsigned int)(*(int *)(p + 0x1E0) - 1) < 2) {
        func_001490A0(p, 0);
    }
}
