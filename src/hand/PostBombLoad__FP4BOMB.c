struct K { int a; int b; };
struct S { char pad[0x1f4]; int f1f4; int f1f8; int f1fc; };
void PostSoLoad(struct S *);
int PvAllocSwImpl__Fi(struct K *);
void PostBombLoad__FP4BOMB(struct S *p) {
    PostSoLoad(p);
    if (p->f1f4) { struct K k; k.a = 0xc0; k.b = 0x10; p->f1fc = PvAllocSwImpl__Fi(&k); }
}
