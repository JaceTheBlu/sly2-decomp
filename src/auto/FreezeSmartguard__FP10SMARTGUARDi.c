#include "m2c_prelude.h"
M2C_UNK func_00187E78(s32);                         /* extern */
M2C_UNK func_001D98A8();                            /* extern */

void FreezeSmartguard__FP10SMARTGUARDi(void *arg0, s32 arg1) {
    func_001D98A8();
    if (arg1 != 0) {
        func_00187E78(M2C_FIELD(arg0, s32 *, 0x10));
    }
}
