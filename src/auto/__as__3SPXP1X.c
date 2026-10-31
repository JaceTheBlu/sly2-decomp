#include "m2c_prelude.h"
M2C_UNK func_00257078(s32 *, M2C_UNK);              /* extern */

void __as__3SPXP1X(s32 **arg0, s32 *arg1) {
    s32 *temp_a0;
    s32 temp_v0;

    if (arg1 != NULL) {
        *arg1 += 1;
    }
    temp_a0 = *arg0;
    if (temp_a0 != NULL) {
        temp_v0 = *temp_a0 - 1;
        *temp_a0 = temp_v0;
        if (temp_v0 == 0) {
            func_00257078(temp_a0, 3);
        }
    }
    *arg0 = arg1;
}
