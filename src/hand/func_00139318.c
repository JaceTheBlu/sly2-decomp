struct G { char pad[0x4070]; int f4070; };
extern struct G g_sw;
void *func_0015E3A8(struct G *, int);
void func_0011A118(void *, void *);
void FreeSlotheapPv__FP8SLOTHEAPPv(void *, void *);
void func_00139318(void *p) {
    func_0011A118(func_0015E3A8(&g_sw, 0x1c), p);
    FreeSlotheapPv__FP8SLOTHEAPPv(&g_sw.f4070, p);
}
