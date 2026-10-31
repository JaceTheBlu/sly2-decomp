struct S { char pad[0x108]; float g; };
extern float D_002A5690;
void func_00185130(struct S *p);
void InitSpire__FP5SPIRE(struct S *p)
{
    func_00185130(p);
    p->g = D_002A5690;
}
