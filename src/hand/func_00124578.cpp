struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(const CRef &r);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
};
struct Q { char pad[0x3C]; void *pv; };
struct W { char pad[0xC]; Q *pq; };
struct G { char pad[0x3F0C]; void *pv; };
extern G g_sw;
extern "C" {
int func_0015E678(G *pg, int k, void *a, Q *b, void *c, int n, void **ap);
CRef func_00124078(int c, void **ap);
CRef func_00124578(void *pbasic, CRef *aref);
}
CRef func_00124578(void *pbasic, CRef *aref)
{
    CRef ref;
    void *ap[0x40];
    Q *pq = (Q *)aref[1].u.pv;
    Q *pqT;
    if (aref[2].m_tagk)
        pqT = ((W *)aref[2].u.pv)->pq;
    else
        pqT = pq;
    void *p0 = aref[0].u.pv;
    G *pg = &g_sw;
    void *pv;
    if (pqT)
        pv = pqT->pv;
    else
        pv = pg->pv;
    int c = func_0015E678(pg, 4, p0, pq, pv, 0x40, ap);
    ref = func_00124078(c, ap);
    return ref;
}
