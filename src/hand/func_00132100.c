struct S { char pad[0xe8]; int fe8; };
extern char g_sw[];
void PostCid48Load(struct S *);
void func_00134320(void *, struct S *);
void func_00132100(struct S *p) { PostCid48Load(p); if (p->fe8) func_00134320(g_sw, p); }
