struct S { char pad[0x38]; float g; char p2[0xC0]; int nfc; };
extern float D_002BE900;
void PostLoLoad__FP2LO(struct S *p);
void func_00183F50(struct S *p)
{
    PostLoLoad__FP2LO(p);
    if (!p->nfc) p->nfc = 7;
    if (p->g == 1e10f) p->g = D_002BE900;
}
