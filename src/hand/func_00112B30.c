typedef struct BASIC { int m0; int m4; int m8; void *pvtbl; } BASIC;
extern char D_002D5120[];
void *__builtin_new(int cb);
void __1M(void *pv);

static inline BASIC *CtorBasic(BASIC *p)
{
    p->pvtbl = D_002D5120;
    p->m0 = 0;
    p->m4 = 0;
    return p;
}

void *func_00112B30(void)
{
    BASIC *p = CtorBasic((BASIC *)__builtin_new(0x160));
    char *pb = (char *)p + 0x60;
    int i = 5;
    do {
        __1M(pb);
        i--;
        pb += 0x20;
    } while (i != -1);
    return p;
}
