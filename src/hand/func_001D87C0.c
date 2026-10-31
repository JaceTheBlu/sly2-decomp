typedef char *va_list;
#define va_arg_pch(ap) (*(char **)((ap += 8) - 8))
struct MSG { int cb; int nKind; };
typedef struct { int c; short *ash; } V;
typedef struct { int a[2]; char ht[1]; } H;
extern H D_003E0EA8;
void *PvAllocStackImpl__FP7SWALLOC(struct MSG *);
int func_001D8720(void *, char *);
static inline int NFind(H *ph, char *pch) { return func_001D8720(ph->ht, pch); }
short func_00233800(char *);
void func_001D87C0(char *pch, va_list ap, V *pv)
{
    va_list apSave = ap;
    char *pchT;
    int i;
    pv->c = 0;
    pv->ash = 0;
    for (pchT = pch; pchT; pchT = va_arg_pch(ap))
        pv->c++;
    if (pv->c) {
        struct MSG msg;
        msg.cb = pv->c * 2;
        msg.nKind = 0x10;
        pv->ash = PvAllocStackImpl__FP7SWALLOC(&msg);
        ap = apSave;
        for (pchT = pch, i = 0; pchT; pchT = va_arg_pch(ap), i++) {
            int n = NFind(&D_003E0EA8, pchT);
            if (n == -1)
                pv->ash[i] = func_00233800(pchT);
            else
                pv->ash[i] = n;
        }
    }
}
