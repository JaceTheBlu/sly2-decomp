#include "m2c_prelude.h"
extern M2C_UNK D_002C3738;
extern M2C_UNK D_002C3748;
extern M2C_UNK D_002C3968;
extern M2C_UNK D_002D9768;
extern f32 g_clock;
extern M2C_UNK D_002DDFA0;
extern M2C_UNK D_002DE578;
extern M2C_UNK D_002DEB30;
extern s32 D_002E1E40;
extern M2C_UNK g_sw;
extern M2C_UNK D_003E126C;
extern M2C_UNK D_003E1278;

void func_001F0538(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x10) - 1;
    M2C_FIELD(arg0, s32 *, 0x10) = temp_v0;
    if (temp_v0 <= 0) {
        __as__3SPXP1X(arg0, 0);
        func_002580A8(arg0 + 4, 0);
        func_001334A8(arg0);
        FreeSlotheapPv__FP8SLOTHEAPPv((s32) &D_003E1278, arg0);
    }
}
