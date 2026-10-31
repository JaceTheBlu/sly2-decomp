void *func_0015E938(void *pv, int k, int id);
void *func_001EC918(int id);
int func_00132B10(void *p, int cid);
void func_001F80D0(void *p, float f);
void SetEyesClosed__FP4EYESf(void *p, float f);
void func_00210678(void *pv, int id1, int id2, float f)
{
    void *p1 = 0;
    void *p2 = 0;
    if (id1 != -1) {
        void *q = func_0015E938(pv, 4, id1);
        if (q && func_00132B10(q, 0x30))
            p1 = q;
    }
    if (id2 != -1) {
        p2 = func_001EC918(id2);
        if (p2 && !func_00132B10(p2, 0x8E))
            p2 = 0;
    }
    if (p1)
        func_001F80D0(p1, f);
    if (p2)
        SetEyesClosed__FP4EYESf(p2, f);
}
