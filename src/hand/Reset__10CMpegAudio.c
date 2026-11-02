struct S { int f0; int f4; char pad[0x28]; char x30[0x20]; char x50[0x20]; char x70[0x10]; };
void func_00232F28(void);
void func_0013D580(void *p);
void func_001B2A80(void *p);
void Reset__10CMpegAudio(struct S *p)
{
    if (p->f0) {
        func_00232F28();
        p->f0 = 1;
        p->f4 = -1;
        func_0013D580(p->x30);
        func_0013D580(p->x50);
        func_001B2A80(p->x70);
    }
}
