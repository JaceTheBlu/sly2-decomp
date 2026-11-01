struct S { char pad[0x1C4]; int x; };
void OnCid48Remove(struct S *p);
void func_001305B8(int a, int b, int c, void *d, float f, float g);
void func_001B0C68(struct S *p)
{
    OnCid48Remove(p);
    func_001305B8(0, 0, 0, &p->x, 0.0f, 0.0f);
}
