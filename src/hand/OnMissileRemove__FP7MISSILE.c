struct S { char pad[0x234]; int x; char pad2[0x268 - 0x238]; char y[4]; };
void OnSoRemove__FP2SO(struct S *p);
void func_001305B8(int a, struct S *b, int c, void *d, float f, float g);
void func_0012E460(void *p);
void OnMissileRemove__FP7MISSILE(struct S *p)
{
    OnSoRemove__FP2SO(p);
    func_001305B8(0, p, 0, &p->x, 0.0f, 1.0f);
    func_0012E460(p->y);
}
