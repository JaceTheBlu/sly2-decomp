typedef int qword __attribute__((mode(TI)));
struct SLOTHEAP { int a[6]; };
extern SLOTHEAP D_00452170, D_00452188, D_004521A0, D_004521B8, D_004521D0, D_004521E8;
extern char D_004520A8[];
extern "C" {
void FreeSlotheapPv__FP8SLOTHEAPPv(void *psh, void *pv);
void func_002550F8(void *pv);
void func_00256120(void *pv);
}
struct NODE;
struct SPM { NODE *p; ~SPM(); };
struct VT { short d; short pad; void (*pfn)(void *); };
struct O21 { char pad[0xC]; VT *vt; };
struct CRef {
    int m_tagk;
    void *m_pv;
    void Decref();
    ~CRef() { Decref(); }
};
struct NV { qword v; int cref; };
struct NM { qword m[4]; int cref; };
struct N2 { int a[2]; int cref; };
struct N3 { int a[3]; int cref; };
struct NODE {
    int cref;
    int x4;
    CRef ref;
    SPM pnext;
    void operator delete(void *pv) { func_002550F8(pv); FreeSlotheapPv__FP8SLOTHEAPPv(D_004520A8, pv); }
};
struct O20 { int cref; ~O20(); };
struct O22 {
    int cref;
    ~O22() { func_00256120(this); }
    void operator delete(void *pv) { FreeSlotheapPv__FP8SLOTHEAPPv(&D_00452170, pv); }
};
void CRef::Decref()
{
    switch (m_tagk) {
    case 0x1A: {
        NV *p = (NV *)m_pv;
        if (--p->cref == 0)
            FreeSlotheapPv__FP8SLOTHEAPPv(&D_00452188, p);
        break;
    }
    case 0x1B: {
        NM *p = (NM *)m_pv;
        if (--p->cref == 0)
            FreeSlotheapPv__FP8SLOTHEAPPv(&D_004521A0, p);
        break;
    }
    case 0x1C: {
        NV *p = (NV *)m_pv;
        if (--p->cref == 0)
            FreeSlotheapPv__FP8SLOTHEAPPv(&D_004521B8, p);
        break;
    }
    case 0x1D: {
        N2 *p = (N2 *)m_pv;
        if (--p->cref == 0)
            FreeSlotheapPv__FP8SLOTHEAPPv(&D_004521D0, p);
        break;
    }
    case 0x1E: {
        N3 *p = (N3 *)m_pv;
        if (--p->cref == 0)
            FreeSlotheapPv__FP8SLOTHEAPPv(&D_004521E8, p);
        break;
    }
    case 0x1F: {
        NODE *p = (NODE *)m_pv;
        if (--p->cref == 0)
            delete p;
        break;
    }
    case 0x20: {
        O20 *p = (O20 *)m_pv;
        if (--p->cref == 0)
            delete p;
        break;
    }
    case 0x21: {
        O21 *p = (O21 *)m_pv;
        if (p)
            p->vt[2].pfn((char *)p + p->vt[2].d);
        break;
    }
    case 0x22: {
        O22 *p = (O22 *)m_pv;
        if (--p->cref == 0 && p) {
            func_00256120(p);
            FreeSlotheapPv__FP8SLOTHEAPPv(&D_00452170, p);
        }
        break;
    }
    }
}
