typedef int qword __attribute__((mode(TI)));
typedef union VU { qword q; float f[4]; } VU;
struct G { char pad[0x90]; qword q90; };
extern struct G g_cm;
extern char g_sw[];
struct S { int pad[4]; void *p10; };
qword func_001A62E8(void *p);
void *func_001C4A48(void *p);
qword func_00150780(struct S *p)
{
    VU v;
    if (p->p10) {
        v.q = func_001A62E8(p->p10);
    } else {
        void *o = func_001C4A48(g_sw);
        if (o) {
            v.q = func_001A62E8(o);
            v.f[2] += 150.0f;
        } else {
            v.q = g_cm.q90;
        }
    }
    return v.q;
}
