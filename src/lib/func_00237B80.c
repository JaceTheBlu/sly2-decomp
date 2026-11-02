// SLY2_CC: tools/compilers/extra/ee-gcc2.9-991111
// SLY2_CFLAGS: -O2 -G0
// SLY2_ASM: gnu-reorder-db
extern int _sceFs_sema;
void s1_SignalSema(int);
void func_00237B80(void)
{
    s1_SignalSema(_sceFs_sema);
}
