#include "m2c_prelude.h"
M2C_UNK func_00129EC8(M2C_UNK *);                   /* extern */
extern M2C_UNK D_0027A10C;
extern M2C_UNK D_0027A1D8;
extern s128 D_002A2DD0;
extern M2C_UNK D_002BAAE8;
extern s128 D_002BC920;
extern s128 D_002BC970;
extern s128 D_002BC980;
extern s32 D_002DD5BC;
extern f32 g_clock;
extern M2C_UNK g_cm;
extern M2C_UNK g_sw;
extern f32 *D_003E0E80;
extern M2C_UNK D_003E1144;
extern M2C_UNK D_004520A8;

s32 FOpenSector__18CBinaryAsyncStreamUiUi(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 0x2C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x28) = arg2;
    M2C_FIELD(arg0, s32 *, 0) = 1;
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    StartSpooling__18CBinaryAsyncStream(arg0);
    return 1;
}
