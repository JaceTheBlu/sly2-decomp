struct S { char pad[0xE0]; float gE0; float gE4; float gE8; char p2[8]; int nF4; int nF8; char p3[8]; float g104; };
void LoadAloFromBrx__FP3ALOP18CBinaryInputStream(struct S *p);
void func_002035A8(struct S *p)
{
    p->gE4 = 0.0f;
    p->gE0 = 75.0f;
    p->gE8 = 0.25f;
    p->g104 = 5000.0f;
    LoadAloFromBrx__FP3ALOP18CBinaryInputStream(p);
    if (p->gE4 == 0.0f) p->gE4 = p->gE0;
    if (p->nF8 == -2) p->nF8 = p->nF4;
}
