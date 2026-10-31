typedef int qword __attribute__((mode(TI)));
struct CTX { int a[4]; };
struct REQ { int cb; int align; };
void func_001AE478(struct CTX *c);
void _$_18CBinaryInputStream(struct CTX *c, int n);
void *PvAllocStackImpl__FP7SWALLOC(struct REQ *r);
void func_001AE5A0(void *dst, void *src, int cb);
int func_001BF900(void *ctx, qword a, qword b, int n);
static __inline__ void *PvAllocReq(struct REQ *preq, int cb, int nKind) { preq->cb = cb; preq->align = nKind; return PvAllocStackImpl__FP7SWALLOC(preq); }
void func_001BFC18(void *ctx, int *pc, qword **ap)
{
    struct CTX c;
    struct REQ req;
    qword **tmp, **prev, **cur, **next, **end;
    int n, k;
    func_001AE478(&c);
    n = *pc;
    end = ap + n;
    tmp = PvAllocReq(&req, n * 4, 0x10);
    tmp[0] = ap[0];
    k = 1;
    prev = ap;
    cur = ap + 1;
    next = ap + 2;
    while (next < end) {
        if (func_001BF900(ctx, **prev, **next, 0)) {
            tmp[k] = *cur;
            prev = cur;
            cur = next++;
            k++;
        } else {
            cur = next++;
        }
    }
    tmp[k] = ap[n - 1];
    k++;
    if (k < n && k >= 3) func_001BFC18(ctx, &k, tmp);
    func_001AE5A0(ap, tmp, k * 4);
    *pc = k;
    _$_18CBinaryInputStream(&c, 2);
}
