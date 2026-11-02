struct VTE { short d; short pad; void (*pf)(); };
struct O { int a[3]; struct VTE *vt; char pad[0x140]; int k; };
struct Q { int a; struct O *o; };
void func_00133590(struct O *p, int k, struct Q *q);
void HandleCid100Message(struct O *p, int k, struct Q *q)
{
    func_00133590(p, k, q);
    if (k == 4) {
        struct O *o = q->o;
        if (o == p && (unsigned)(o->k - 1) < 2) o->vt[76].pf((char *)o + o->vt[76].d, 3);
    }
}
