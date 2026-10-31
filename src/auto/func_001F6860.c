#include "m2c_prelude.h"
M2C_UNK CopyAb__FPvT0Ui(s32, s32, s32);             /* extern */
void **PvAllocStackImpl__FP7SWALLOC(s32 *);                        /* extern */
extern s128 D_002A2DD0;
extern M2C_UNK D_002C3C20;
extern M2C_UNK D_002C44F0;
extern void *g_pdliFirst;
extern f32 D_002DDED0;
extern f32 D_002DDED4;
extern M2C_UNK g_sw;
extern void *D_003E1218;
extern void *D_003E126C;
extern M2C_UNK D_003E15A8;
extern s32 *D_003E15C0;

void func_001F6860(s32 arg0, s32 arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0xEC);
    if (temp_a2 != NULL) {
        M2C_FIELD(temp_a2, s64 *, 0x70) = (s64) ((M2C_FIELD(temp_a2, s64 *, 0x70) & ~4) | ((arg1 & 1) * 4));
        func_001F4E28(arg0);
    }
}
