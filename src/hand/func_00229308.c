struct N { int a; void *o; int b; struct N *next; };
struct S { char pad[0x150]; struct N *first; };
extern char g_sw[];
void func_001F2D48(struct S *p);
void func_00229738(void *o, struct N *n);
void func_002296C0(void *g, struct N *n);
void func_00229308(struct S *p)
{
    struct N *n;
    func_001F2D48(p);
    for (n = p->first; n; n = n->next) func_00229738(n->o, n);
    func_002296C0(g_sw, p->first);
    p->first = 0;
}
