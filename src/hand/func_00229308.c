struct N { int a; void *o; int b; struct N *next; };
struct S { char pad[0x150]; struct N *first; };
extern char g_sw[];
void OnCid48Remove(struct S *p);
void RemoveSoXa__FP2SOP2XA(void *o, struct N *n);
void FreeSwXaList__FP2SWP2XA(void *g, struct N *n);
void func_00229308(struct S *p)
{
    struct N *n;
    OnCid48Remove(p);
    for (n = p->first; n; n = n->next) RemoveSoXa__FP2SOP2XA(n->o, n);
    FreeSwXaList__FP2SWP2XA(g_sw, p->first);
    p->first = 0;
}
