typedef char *va_list;
#define va_start(ap, last) (ap = ((char *)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
typedef struct { int tagk; int tag; } CREF;
typedef struct { int a[4]; } FRAME;
typedef struct { int c; void *p; int pad[2]; } LIST;
extern char D_003E0EA8[];
extern char D_003D4A60[];
void func_001AE478(FRAME *);
void _$_18CBinaryInputStream(FRAME *, int);
void func_00129EC8(CREF *);
void func_001D87C0(void *p, va_list ap, LIST *pv);
int func_001D7E80(void *, LIST *, void *);
int func_001D8C10(void *p, ...)
{
    CREF ref;
    FRAME fr;
    LIST l;
    va_list ap;
    int r;
    ref.tagk = -1;
    func_001AE478(&fr);
    va_start(ap, p);
    func_001D87C0(p, ap, &l);
    r = func_001D7E80(D_003E0EA8, &l, D_003D4A60);
    _$_18CBinaryInputStream(&fr, 2);
    func_00129EC8(&ref);
    return r;
}
