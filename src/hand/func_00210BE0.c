typedef struct { char *pch; char *pchOut; } ENT;
typedef struct { int c; ENT *a; int x8; int xC; } TBL;
typedef struct { int a[4]; } ALLOC;
extern struct G { char pad[0x4640]; int f; } g_sw;
extern ALLOC *func_00116A98(ALLOC *, int, int);
extern char *func_0013E368(struct G *, char *);
extern int func_0021ED28(char *);
extern char *func_001169D8(ALLOC *, char *, int);

void func_00210BE0(TBL *p)
{
    ALLOC al;
    int i;
    if (g_sw.f == 0)
        return;
    func_00116A98(&al, p->x8, p->xC);
    for (i = 0; i < p->c; i++) {
        ENT *e = &p->a[i];
        e->pchOut = func_0013E368(&g_sw, e->pch);
        if (func_0021ED28(e->pchOut))
            e->pchOut = func_001169D8(&al, e->pchOut, 4);
        else
            e->pchOut = 0;
    }
}
