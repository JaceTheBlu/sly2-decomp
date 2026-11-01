struct E { int oidA; void *pA; int oidB; void *pB; int oidC; void *pC; int oidD; void *pD; int n; };
struct S { char pad[0x1010]; int c; struct E *ae; };
extern char g_sw[];
void *PloFindSwObject__FP2SWi3OIDP2LO(void *g, int k, int oid, struct S *p);
void PostCid56Load(struct S *p);
void PostCid59Load(struct S *p)
{
    int i;
    PostCid56Load(p);
    for (i = 0; i < p->c; i++) {
        struct E *pe = &p->ae[i];
        pe->pA = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pe->oidA, p);
        pe->pB = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pe->oidB, p);
        pe->pC = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pe->oidC, p);
        pe->pD = PloFindSwObject__FP2SWi3OIDP2LO(g_sw, 4, pe->oidD, p);
    }
}
