#include "m2c_prelude.h"
s32 FMemcardThreadValid__FP7MEMCARD();              /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
M2C_UNK func_002348B0(s32, M2C_UNK);                /* extern */

void SetMemcardThreadHighPrio__FP7MEMCARD(void *arg0) {
    if (FMemcardThreadValid__FP7MEMCARD() != 0) {
        func_002348B0(M2C_FIELD(arg0, s32 *, 4), 1);
    }
    WaitSema(M2C_FIELD(arg0, s32 *, 0));
    SignalSema(M2C_FIELD(arg0, s32 *, 0));
}
