#include "m2c_prelude.h"
M2C_UNK func_00129EC8(M2C_UNK *);                   /* extern */
extern M2C_UNK D_0027A10C;
extern M2C_UNK D_0027A1D8;
extern M2C_UNK D_002BAAE8;
extern f32 D_002DDED0;
extern M2C_UNK g_sw;
extern f32 *D_003E0E80;
extern M2C_UNK D_003E1144;
extern M2C_UNK D_004520A8;

s32 func_00132600(s32 arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = 0;
    if (M2C_FIELD(arg1, s32 *, 8) == 2) {
        var_a2 = FOpenSector__18CBinaryAsyncStreamUiUi(arg0, M2C_FIELD(arg1, s32 *, 0), M2C_FIELD(arg1, s32 *, 4));
    }
    return var_a2;
}
