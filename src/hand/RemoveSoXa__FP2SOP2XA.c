struct N { int a[2]; struct N *next; };
struct S { char pad[0x138]; struct N *first; };
void func_001F5078(struct S *p, struct N *n);
void RemoveSoXa__FP2SOP2XA(struct S *p, struct N *n)
{
    struct N **pp;
    for (pp = &p->first; *pp; pp = &(*pp)->next) {
        if (*pp == n) { *pp = n->next; n->next = 0; break; }
    }
    func_001F5078(p, n);
}
