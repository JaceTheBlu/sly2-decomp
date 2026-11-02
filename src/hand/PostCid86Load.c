struct S { char pad[0xe8]; int fe8; };
extern char g_sw[];
void PostSoLoad(struct S *);
void func_00134320(void *, struct S *);
void PostCid86Load(struct S *p) { PostSoLoad(p); if (p->fe8) func_00134320(g_sw, p); }
