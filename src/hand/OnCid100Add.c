struct S { char pad[0x164]; void *x; char y[4]; };
void OnSoAdd__FP2SO(struct S *p);
void func_001F1448(void *a, struct S *p, int b, int c, void *d);
void OnCid100Add(struct S *p)
{
    OnSoAdd__FP2SO(p);
    if (p->x) func_001F1448(p->x, p, -1, 0, p->y);
}
