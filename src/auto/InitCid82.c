#include "m2c_prelude.h"
M2C_UNK InitCid80();                            /* extern */

void InitCid82(void *arg0) {
    InitCid80();
    M2C_FIELD(arg0, f32 *, 0x274) = 1500.0f;
}
