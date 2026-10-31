#include "m2c_prelude.h"
M2C_UNK func_001A5C48();                            /* extern */
M2C_UNK func_00221178(s32, M2C_UNK);                /* extern */

void OnStepguardAdd__FP9STEPGUARD(void *arg0) {
    s32 temp_a0;

    func_001A5C48();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x110);
    if (temp_a0 != 0) {
        func_00221178(temp_a0, 0);
    }
}
