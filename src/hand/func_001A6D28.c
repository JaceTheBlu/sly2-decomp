struct VTE { short d; short pad; void (*pfn)(); };
struct ALO {
    char pad[0x28];
    unsigned long b0 : 52;
    long n52 : 4;
    unsigned int b56 : 4;
    unsigned int f60 : 1;
};
struct SW { struct ALO *palo; };
struct O {
    char pad[0xC];
    struct VTE *vt;
    struct O *pNext;
    struct SW *psw;
    char pad2[0x15];
    unsigned char b2D;
};
extern char g_sw[];
void func_00147E88(void *, void *);
void func_001A6D28(struct O *p, int b)
{
    struct O *q;
    if (p->psw->palo->f60)
        func_00147E88(g_sw, p->psw);
    {
        struct VTE *e = &p->vt[46];
        ((void (*)(void *, int))e->pfn)((char *)p + e->d, b);
    }
    for (q = p->pNext; q; q = q->pNext)
        q->b2D |= b;
}
