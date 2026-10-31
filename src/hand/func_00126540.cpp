struct CRef {
    int m_tagk; union { int n; float g; void *pv; } u;
    CRef() { m_tagk = -1; }
    CRef(const CRef &r);
    void Decref();
    void InitTag(int tagk);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
};
typedef struct Q { char pad[0xC]; void *pv0C; void *pv10; } Q;
typedef struct R { char pad[0x10]; Q *pq; } R;
typedef struct P { char pad[0xC]; R *pr; } P;
extern "C" {
CRef func_00127838(void *pv, CRef *aref);
CRef RefAddBinding__6CFrameUiP4CRef(CRef *aref, void *pv, CRef *pref);
CRef func_00126540(P *p, CRef *aref);
}
CRef func_00126540(P *p, CRef *aref) { CRef ref; Q *pq = p->pr->pq; ref = func_00127838(pq->pv10, aref); ref = RefAddBinding__6CFrameUiP4CRef(aref, pq->pv0C, &ref); return ref; }
