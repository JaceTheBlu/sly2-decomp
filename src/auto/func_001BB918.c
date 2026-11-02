#include "m2c_prelude.h"
M2C_UNK CopyAb__FPvT0Ui(s32 *, s32, s32);           /* extern */
M2C_UNK func_001573C0(void *, s32, M2C_UNK, s32);   /* extern */
M2C_UNK __4GIFS(void *, s64);                 /* extern */
s32 *PvAllocStackImpl__FP7SWALLOC(s32 *, s32, s32, s32);           /* extern */
extern f32 D_002A76D0;
extern f32 D_002A76D4;
extern f32 D_002C0AB0;
extern f32 D_002C0AB4;
extern f32 D_002C0AB8;
extern f32 D_002C0ABC;
extern f32 D_002C0AC0;
extern f32 D_002C0AC4;
extern M2C_UNK D_002C0BF8;
extern M2C_UNK D_002C1F00;
extern M2C_UNK D_002C1F10;
extern s32 *g_pdliFirst;
extern M2C_UNK D_003DD020;
extern M2C_UNK D_003DD4BC;
extern s32 D_003E1A40;
extern s32 D_003E1A4C;
extern M2C_UNK D_003E1A78;

/*
Decompilation failure in function func_001BB648:

Found jr instruction at chunk.s line 67, but the corresponding jump table is not provided.

Please include it in the input .s file(s), or in an additional file.

*/

s32 func_001BB918(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x150);
    var_v0 = temp_a0 < 8;
    if (var_v0 != 0) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0x154) + (temp_a0 * 8);
        M2C_FIELD(arg0, s32 *, 0x150) = (s32) (temp_a0 + 1);
        M2C_FIELD(var_v0, s32 *, 4) = arg2;
        M2C_FIELD(var_v0, s32 *, 0) = arg1;
    }
    return var_v0;
}
