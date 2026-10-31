#include "m2c_prelude.h"
s32 func_00242AB8();                                /* extern */
extern s32 D_002BD4C4;

s32 FValidCdMmode__Fv(void) {
    s32 temp_v0;

    temp_v0 = func_00242AB8();
    if (D_002BD4C4 != temp_v0) {
        D_002BD4C4 = temp_v0;
    }
    return D_002BD4C4 == 0x14;
}
