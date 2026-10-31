#include "m2c_prelude.h"
extern s128 D_002A2DC0;
extern s128 D_002A2DD0;
extern f32 D_002A5654;
extern f32 D_002A5658;
extern f32 D_002A565C;
extern f32 D_002BE7B8;
extern f32 D_002BE7BC;
extern f32 D_002BE7C0;
extern f32 D_002BE7C4;
extern s128 D_002BE7D0;
extern M2C_UNK D_002BE800;
extern f32 D_002BE880;
extern f32 D_002DDED0;
extern f32 D_002DDED4;
extern M2C_UNK D_002DEB30;
extern s32 D_002DFB80;
extern s32 D_002E1E00;
extern M2C_UNK D_003DD020;
extern M2C_UNK g_sw;

s32 InitVismap__FP6VISMAP(s32 arg0, s32 arg1) {
    s32 temp_v0;

    func_001CB518(arg0, arg1);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x180);
    M2C_FIELD(arg0, s32 *, 0x184) = temp_v0;
    return temp_v0;
}
