#include "m2c_prelude.h"
M2C_UNK CloneAlo__FP3ALOT0();                            /* extern */

void CloneEmitter__FP7EMITTERT0(void *arg0) {
    s32 *temp_v1;

    CloneAlo__FP3ALOT0();
    temp_v1 = M2C_FIELD(arg0, s32 **, 0xE4);
    *temp_v1 += 1;
}
