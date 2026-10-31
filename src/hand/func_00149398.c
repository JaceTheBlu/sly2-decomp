struct P2 { int a, b; };
void func_001A5C48(void *p);
void func_00148740(void *p);
void func_00149718(void *p, int n);
int PvAllocSwImpl__Fi(struct P2 *p);
void func_00149398(char *p)
{
    func_001A5C48(p);
    func_00148740(p + 0x130);
    func_00149718(p, 0);
    if (*(int *)(p + 0x2C8)) {
        struct P2 s;
        s.a = 0x100;
        s.b = 0x10;
        *(int *)(p + 0x2C4) = PvAllocSwImpl__Fi(&s);
    }
}
