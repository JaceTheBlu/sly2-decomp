struct S { char pad[0x38]; float g38; };
extern float D_002C1EC0;
void PostLoLoad__FP2LO(struct S *p);
float func_001E7D90(struct S *p);
void func_001CB950(struct S *p)
{
    PostLoLoad__FP2LO(p);
    if (p->g38 == 1e10f) p->g38 = func_001E7D90(p) + D_002C1EC0;
}
