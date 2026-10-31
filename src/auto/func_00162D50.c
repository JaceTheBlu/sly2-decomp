#include "m2c_prelude.h"
s32 FIsBasicDerivedFrom__FP5BASIC3CID(s32, M2C_UNK);                    /* extern */
M2C_UNK func_00143380(s32);                         /* extern */
M2C_UNK func_001619A0(M2C_UNK *, M2C_UNK, s32);     /* extern */
M2C_UNK func_001628B8(s32);                         /* extern */
s32 func_001633E8();                                /* extern */
s32 func_001C4840(M2C_UNK *);                       /* extern */
extern M2C_UNK D_002DEB30;
extern M2C_UNK g_sw;

void func_00162D50(s32 arg0) {
    s32 temp_v0;

    if (func_001633E8() == 0) {
        func_001619A0(&D_002DEB30, 0x1C, arg0);
        temp_v0 = func_001C4840(&g_sw);
        if ((temp_v0 != 0) && (FIsBasicDerivedFrom__FP5BASIC3CID(temp_v0, 0x34) != 0)) {
            func_00143380(temp_v0);
        }
        func_001628B8(arg0);
    }
}
