struct PMF { short delta; short pad; int (*pfn)(void *); };
struct S { char pad[0x40]; int x40; };
extern struct PMF D_002A6E88, D_002A6D88, D_002A6E90;
extern char D_002F633C[];
void func_001AD3E0(void);
void CreateMemcardThread__FP7MEMCARDii(void *t, struct PMF pmf);
void func_001ACB58(struct S *s, int n);
void func_001AD168(struct S *s)
{
    switch (s->x40) {
    case 0x1C:
        func_001AD3E0();
        break;
    case 0x12:
        CreateMemcardThread__FP7MEMCARDii(D_002F633C, D_002A6E88);
        func_001ACB58(s, 0x13);
        break;
    case 0x15:
        CreateMemcardThread__FP7MEMCARDii(D_002F633C, D_002A6D88);
        func_001ACB58(s, 0x16);
        break;
    case 0x20:
        CreateMemcardThread__FP7MEMCARDii(D_002F633C, D_002A6E90);
        func_001ACB58(s, 0x21);
        break;
    }
}
