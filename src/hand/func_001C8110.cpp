extern "C" {
void func_001AE478(void *p);
void _$_18CBinaryInputStream(void *p, int n);
void func_00129EC8(void *p);
void *func_001C8090(void);
}
class FRAME { int a[4]; public: FRAME() { func_001AE478(this); } ~FRAME() { _$_18CBinaryInputStream(this, 2); } };
struct CRef { int m_tagk; int m_tag; };
extern char D_003D4A60[];
extern "C" void func_002581C0(CRef *pref, void *pv, void *p);
static inline int NFromPv(void *pv) { CRef ref; int n; func_002581C0(&ref, pv, D_003D4A60); n = ref.m_tag; func_00129EC8(&ref); return n; }
extern "C" int func_001C8110(void);
int func_001C8110(void)
{
    FRAME frame;
    void *pv = func_001C8090();
    if (!pv) return 0;
    return NFromPv(pv);
}
