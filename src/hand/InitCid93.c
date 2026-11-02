struct S { char p0[0x1A0]; float x1A0; char p1[0x1D0 - 0x1A4]; float x1D0, x1D4, x1D8, x1DC, x1E0, x1E4;
    char p2[0x230 - 0x1E8]; float x230, x234; int x238; int x23C; int x240; };
void func_001C4E50(struct S *p);
void InitCid93(struct S *p)
{
    func_001C4E50(p);
    p->x1D8 = 45.0f;
    p->x1DC = 75.0f;
    p->x1D0 = 250.0f;
    p->x1D4 = 50.0f;
    p->x1E4 = 0.2f;
    p->x1E0 = 0.65f;
    p->x1A0 = 0.25f;
    p->x23C = 10;
    p->x240 = 20;
    p->x230 = 4.0f;
    p->x234 = 5.0f;
}
