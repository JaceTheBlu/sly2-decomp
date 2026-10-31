struct L { char pad[0x24]; struct L *next; char pad2[0x64 - 0x28]; struct L *first; char pad3[0x70 - 0x68]; struct L *end; char pad4[0xA4 - 0x74]; int c; void **ap; };
int func_00132B10(void *, int);
void SetEyesClosed__FP4EYESf(void *, float);
void func_001F80D0(struct L *p, float f)
{
    int i;
    struct L *q;
    for (i = 0; i < p->c; i++) {
        void *pv = p->ap[i];
        if (func_00132B10(pv, 0x8E)) SetEyesClosed__FP4EYESf(pv, f);
    }
    for (q = p->first; q != p->end; q = q->next)
        if (func_00132B10(q, 0x30)) func_001F80D0(q, f);
}
