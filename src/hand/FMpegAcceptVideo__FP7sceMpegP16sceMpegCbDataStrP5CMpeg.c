struct M { int a, b; int n8; unsigned int nC; };
struct S { char pad[0x160]; char x160[0x10]; unsigned int c170; };
void func_0013D7D0(void *p, unsigned int a, int b);
int FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg(void *a, struct M *pm, struct S *p)
{
    if (p->c170 < pm->nC) return 0;
    func_0013D7D0(p->x160, pm->nC, pm->n8);
    return 1;
}
