struct N { int a[3]; struct N *next; };
void FreeSlotheapPv__FP8SLOTHEAPPv(void *pool, struct N *n);
void FreeSwXaList__FP2SWP2XA(char *p, struct N *n)
{
    while (n) {
        struct N *next = n->next;
        FreeSlotheapPv__FP8SLOTHEAPPv(p + 0x40E8, n);
        n = next;
    }
}
