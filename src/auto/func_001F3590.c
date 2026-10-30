#include "m2c_prelude.h"
M2C_UNK func_00117ED0(s32, s32);                    /* extern */
extern f32 D_002C3B90;
extern M2C_UNK D_002C44F0;
extern void *D_002DD2FC;
extern M2C_UNK D_002DDED0;
extern f32 D_002DDED4;
extern M2C_UNK g_sw;
extern M2C_UNK D_003E11AC;
extern M2C_UNK D_003E11B8;
extern M2C_UNK D_003E12D4;

s32 func_001F3590(s32 arg0) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0_2 = M2C_FIELD(arg0, void **, 0xE8);
    temp_v0_3 = temp_v0_2 + 0x80;
    M2C_FIELD(temp_v0_2, s32 *, 0x80) = 0;
    M2C_FIELD(temp_v0_3, f32 *, 8) = -1750.0f;
    M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), s32 *, 0xC0) = 3;
    temp_v0 = M2C_FIELD(arg0, void **, 0xE8);
    M2C_FIELD(temp_v0, s32 *, 0xA0) = 3;
    return (s32) temp_v0;
}
