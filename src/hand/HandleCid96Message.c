struct M { char pad[0x14]; int n; };
struct S { char pad[0x1A4]; int n1a4; char pad2[0x1C4 - 0x1A8]; struct M *pm; };
void func_00133590(struct S *p, int msg, struct M *pm);
void func_001B1328(struct S *p, int n);
void HandleCid96Message(struct S *p, int msg, struct M *pm)
{
    func_00133590(p, msg, pm);
    if (msg == 2 && pm == p->pm && pm->n == p->n1a4) func_001B1328(p, 4);
}
