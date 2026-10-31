// SLY2_CC: tools/compilers/extra/ee-gcc2.9-991111
// SLY2_CFLAGS: -O2 -G0 
// SLY2_ASM: gnu-reorder-db
struct SemaParam { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; };
extern int _sceFs_sema;
extern char D_002AAA98[];
int func_00234A20(struct SemaParam *);
void _sceFsSemInit(void)
{
    struct SemaParam p;
    if (_sceFs_sema == -1) {
        p.option = (unsigned int)D_002AAA98;
        p.initCount = 1;
        p.maxCount = 1;
        _sceFs_sema = func_00234A20(&p);
    }
}
