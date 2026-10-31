struct O { char pad[0x40]; float g; };
struct P { char pad[0x30]; struct O *po; };
void SeekAsega__FP5ASEGA4SEEKff(struct O *, int, float, float);
void RetractAsega__FP5ASEGA(struct O *);
void func_001F0FA0(struct P *);
void func_001F08D0(struct P *p)
{
    struct O *po = p->po;
    if (po) {
        p->po = 0;
        if (po->g < 0.0f) SeekAsega__FP5ASEGA4SEEKff(po, 0, 0.0f, po->g);
        else SeekAsega__FP5ASEGA4SEEKff(po, 2, 0.0f, po->g);
        RetractAsega__FP5ASEGA(po);
        func_001F0FA0(p);
    }
}
