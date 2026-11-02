#include "m2c_prelude.h"
M2C_UNK func_00154038(s32, s32, M2C_UNK);           /* extern */
M2C_UNK HandleStepguardMessage__FP9STEPGUARD5MSGIDPv();                            /* extern */
s32 func_00209A68(s32, M2C_UNK);                    /* extern */

void func_0014B218(s32 arg0, s32 arg1, void *arg2) {
    void *temp_v0;

    HandleStepguardMessage__FP9STEPGUARD5MSGIDPv();
    if ((func_00209A68(arg0, 0x24) == 0) && (arg1 == 0xB)) {
        temp_v0 = M2C_FIELD(arg2, void **, 0);
        if (temp_v0 == arg0) {
            func_00154038(M2C_FIELD(temp_v0, s32 *, 0xF64), M2C_FIELD(arg2, s32 *, 4), 1);
        }
    }
}
