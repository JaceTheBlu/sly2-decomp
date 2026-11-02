#include "m2c_prelude.h"
M2C_UNK Read__18CBinaryInputStreamiPv(s32, s32, s32);               /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, s32);                    /* extern */
extern s128 D_002A2DD0;
extern f32 D_002A8124;
extern f32 D_002A8130;
extern f32 D_002A8134;
extern M2C_UNK D_002D8C08;
extern f32 g_clock;
extern M2C_UNK g_cm;
extern M2C_UNK D_002DDFA0;
extern M2C_UNK D_002DE440;
extern M2C_UNK g_sw;
extern M2C_UNK D_003E1560;

void func_001E1B68(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x10) - 1;
    M2C_FIELD(arg0, s32 *, 0x10) = temp_v0;
    if (temp_v0 <= 0) {
        __as__3SPXP1X(arg0, 0);
        func_002580A8(arg0 + 4, 0);
        func_001334A8(arg0);
        FreeSlotheapPv__FP8SLOTHEAPPv((s32) &D_003E1560, arg0);
    }
}
