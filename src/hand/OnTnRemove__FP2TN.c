struct S { char p0[0x160]; void *p160; int a164; };
void PostSoLoad(struct S *p);
void func_001F1448(void *a, struct S *p, int b, int c, int *pn);
void func_001D4FA0(struct S *p, int n);
void OnTnRemove__FP2TN(struct S *p) {
    PostSoLoad(p);
    func_001F1448(p->p160, p, -1, 0, &p->a164);
    func_001D4FA0(p, 0);
}
