#include "m2c_prelude.h"
M2C_UNK func_001CC2E8(void *);                      /* extern */

void EnsureAloSfx__FP3ALO(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x18D8) == 0) {
        func_001CC2E8(arg0 + 0x17D0);
    }
}
