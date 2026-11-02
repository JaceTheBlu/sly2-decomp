struct N { int pad[2]; void *p8; char pad2[0xAC - 0xC]; struct N *next; };
struct G;
extern struct G g_sw;
void func_001F5078(void *);
void func_001A7E10(struct G *, struct N *);
void func_001F4DA8(void *pa, void *pb, struct N **ppn)
{
    struct N *pfree = 0;
    struct N *pn;
loop:
    pn = *ppn;
    if (pn) {
        int i = pn->p8 == pa;
        if (((struct N *)((char *)pn + (i << 6)))->p8 == pb) {
            *ppn = pn->next;
            pn->next = pfree;
            pfree = pn;
        } else {
            ppn = &pn->next;
        }
        goto loop;
    }
    if (pfree) {
        func_001F5078(pa);
        func_001A7E10(&g_sw, pfree);
    }
}
