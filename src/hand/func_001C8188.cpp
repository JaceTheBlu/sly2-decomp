extern "C" {
void *func_001AE478(void *p);
void _$_18CBinaryInputStream(void *p, int n);
void func_00129EC8(void *p);
void *func_001291A8(void *p, const void *q);
void *func_001C8090(void);
void func_001ABD98(void *p, int n);
}
class FRAME { public: FRAME() { func_001AE478(this); } ~FRAME() { _$_18CBinaryInputStream(this, 2); } };
struct CRef {
    int m_tagk; int m_tag;
    CRef() {}
    CRef(int f) { m_tagk = 0x17; m_tag = f; }
    CRef(const CRef &r) { func_001291A8(this, &r); }
    ~CRef() { func_00129EC8(this); }
};
extern char D_003D4A60[];
extern char D_002E65E0[];

extern "C" CRef func_00258200(void *pv, const CRef &ref, void *p);
struct RAW { int m_tagk; int m_tag; };
extern "C" RAW *func_002581C0(RAW *pr, void *pv, void *p);
static inline int NFromPv(void *pv,RAW &ref) { int n; func_002581C0(&ref,pv,D_003D4A60);n=ref.m_tag;func_00129EC8(&ref);return n; }
static inline void SetPv(void *pv,const CRef&r) { CRef arg(r); const CRef &ret=func_00258200(pv,arg,D_003D4A60); }
extern "C" void func_001C8188(int f);
void func_001C8188(int f)
{
    FRAME frame; RAW ref;
    void *pv = func_001C8090();
    if (!pv) return;
    if (f) {
        if (NFromPv(pv,ref) == 0)
            func_001ABD98(D_002E65E0, 0);
    }
    { CRef r(f!=0);SetPv(pv,r); }
}
