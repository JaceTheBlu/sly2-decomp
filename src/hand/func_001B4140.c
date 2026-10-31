struct P { char pad[0x10C]; int n10C; int pad1; int n114; int a118[26]; int a180[48]; volatile int n240; };
extern int D_002DEDBC;
void Reset__10CMpegAudio(int *pn);
void Close__10CMpegAudio(int *pn);
int func_0024B590(int *pn);
int func_0024B530(int *pn);
void func_001B4140(struct P *p)
{
    p->n114 = 0;
    p->n10C = 0;
    Reset__10CMpegAudio(p->a180);
    Close__10CMpegAudio(p->a180);
    func_0024B590(p->a118);
    func_0024B530(p->a118);
    while (p->n240)
        __asm__ __volatile__("");
    D_002DEDBC = 3;
}
