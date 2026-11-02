struct N { int a; void *o; int b; struct N *next; };
struct S { char pad[0x150]; struct N *first; };
extern char g_sw[];
void OnSoRemove__FP2SO(struct S *p);
void RemoveSoXa__FP2SOP2XA(void *o, struct N *n);
void FreeSwXaList__FP2SWP2XA(void *g, struct N *n);
void OnCid89Remove(struct S *p)
{
    struct N *n;
    OnSoRemove__FP2SO(p);
    for (n = p->first; n; n = n->next) RemoveSoXa__FP2SOP2XA(n->o, n);
    FreeSwXaList__FP2SWP2XA(g_sw, p->first);
    p->first = 0;
}
