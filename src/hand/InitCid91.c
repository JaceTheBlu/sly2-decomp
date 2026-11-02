struct S { char pad[0x1A0]; float a1A0; char p1[0x1D0 - 0x1A4]; float a1D0, a1D4, a1D8, a1DC, a1E0, a1E4; char p2[0x230 - 0x1E8]; float a230, a234; };
void func_001C4E50(struct S *p);
void InitCid91(struct S *p)
{
    func_001C4E50(p);
    p->a1D8 = 45.0f;
    p->a1DC = 65.0f;
    p->a1D0 = 250.0f;
    p->a1D4 = 150.0f;
    p->a1E0 = 0.5f;
    p->a1E4 = 0.25f;
    p->a1A0 = 0.25f;
    p->a230 = 5.0f;
    p->a234 = 5.0f;
}
