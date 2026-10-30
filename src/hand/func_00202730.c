struct G;
extern struct G g_sw;
struct S { char pad[0xBC]; int oid; };
const char *func_0013E368(struct G *p, int oid);
const char *func_00202730(struct S *p) { if (p->oid == -1) return 0; return func_0013E368(&g_sw, p->oid); }
