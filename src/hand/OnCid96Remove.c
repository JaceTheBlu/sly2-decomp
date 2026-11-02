struct S { char pad[0x1C4]; int x; };
void OnSoRemove__FP2SO(struct S *p);
void func_001305B8(int a, int b, int c, void *d, float f, float g);
void OnCid96Remove(struct S *p)
{
    OnSoRemove__FP2SO(p);
    func_001305B8(0, 0, 0, &p->x, 0.0f, 0.0f);
}
