struct S { char pad[0x1A0]; float g1a0; char pad2[0x2C]; float g1d0, g1d4, g1d8, g1dc, g1e0, g1e4; };
void func_001C4E50(struct S *p);
void InitCid92(struct S *p)
{
    func_001C4E50(p);
    p->g1d8 = 35.0f; //P
    p->g1dc = 35.0f; //P
    p->g1d0 = 500.0f; //P
    p->g1d4 = 250.0f; //P
    p->g1e4 = 0.6f; //P
    p->g1e0 = 0.6f; //P
    p->g1a0 = 0.75f; //P
}
