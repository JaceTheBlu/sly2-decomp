struct S { char pad[0xE0]; int a; int b; char c[0x10]; char d[4]; };
void func_00231768(struct S *p, void *q);
int func_00117C80(void *q);
void func_00117FD0(void *q, void *a);
void ReadVbsp__18CBinaryInputStreamPiPP4VBSP(void *q, void *a, void *b);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(struct S *p, void *q);
void LoadCid5FromBrx(struct S *p, void *q)
{
    func_00231768(p, q);
    p->a = func_00117C80(q);
    func_00117FD0(q, p->d);
    ReadVbsp__18CBinaryInputStreamPiPP4VBSP(q, p->d, p->c);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(p, q);
}
