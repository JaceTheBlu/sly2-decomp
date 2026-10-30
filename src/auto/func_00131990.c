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

void func_00131990(s32 arg0, s32 arg1) {
    if ((func_00131968(arg0) == 0) && (arg1 != M2C_FIELD(arg0, s32 *, 0x58))) {
        if (arg1 != 0) {
            func_0020EFC0((s32) &g_sw, 3);
        } else {
            func_0020F030((s32) &g_sw, 3);
        }
        M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    }
}
