struct O {
    char pad[0x10];
    struct O *pParent;
    void *pv14;
    char pad2[0x10];
    unsigned long b0 : 52;
    long n52 : 4;
    unsigned int b56 : 4;
    unsigned int f60 : 1;
};
extern char g_sw[];
void func_00147E88(void *, void *);
void func_001A6CA8(struct O *p, int n)
{
    if (n != p->n52) {
        p->n52 = n;
        if (!p->pParent && p->f60 != 0)
            func_00147E88(g_sw, p->pv14);
    }
}
