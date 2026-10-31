struct X { char pad[0x18]; float af[4]; };
void func_0014D1F8(struct X *p);
void SetClockRate__FP5CLOCK3CRKf(struct X *p, int i, float f)
{
    p->af[i] = f;
    func_0014D1F8(p);
}
