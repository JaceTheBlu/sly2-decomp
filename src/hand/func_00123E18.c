typedef struct CRef { int m_tagk; union { int n; float g; void *pv; } u; } CRef;
void Decref__4CRef(CRef *pref);
void InitTag__4CRef(CRef *pref, int tagk);
void func_00129DA8(CRef *pref, CRef *prefSrc);
CRef *func_001291A8(CRef *pref, CRef *prefSrc);
extern float g_clock;
CRef *func_00123E18(CRef *ret, void *pbasic, CRef *aref)
{
    CRef ref;
    CRef refT;
    char *p;
    float g;
    InitTag__4CRef(&ref, 0x24);
    p = (char *)aref[0].u.pv;
    func_00129DA8(&refT, &aref[1]);
    g = refT.u.g;
    Decref__4CRef(&refT);
    *(float *)(p + 0x30) = g_clock + g;
    func_001291A8(ret, &ref);
    Decref__4CRef(&ref);
    return ret;
}
