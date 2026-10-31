typedef struct { char pad[0x50]; int c; } LIST;
typedef struct {
    char pad[0x184];
    LIST *plist;
    void *x188;
    char pad18c[0x220 - 0x18C];
    int c;
    void *a[8];
} OBJ;
void *func_001F07E8(void *);
int IsmsFindSmRequired__FP2SM3OID(LIST *, void *);
void *func_001F04F8(LIST *, int);
void func_001F0660(void *, void *);
void func_001F1448(int, OBJ *, int, int, void **);
void func_001D77D0(OBJ *p, int d)
{
    int i0;
    int i;
    if (p->x188 == 0)
        return;
    i = IsmsFindSmRequired__FP2SM3OID(p->plist, func_001F07E8(p->x188));
    i0 = i;
    for (;;) {
        void *pv;
        int j;
        i += d;
        if (i < 0)
            i = p->plist->c - 1;
        else if (i >= p->plist->c)
            i = 0;
        pv = func_001F04F8(p->plist, i);
        for (j = 0; j < p->c; j++) {
            if (p->a[j] == pv) {
                func_001F0660(p->x188, pv);
                return;
            }
        }
        if (d == 0)
            d = 1;
        else if (i == i0)
            break;
    }
    func_001F1448(0, p, -1, 0, &p->x188);
}
