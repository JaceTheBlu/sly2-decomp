struct S { char pad[0x188]; int n; };
void InitCid71(struct S *p);
void InitCid74(struct S *p)
{
    InitCid71(p);
    p->n = 10;
}
