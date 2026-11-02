#include "m2c_prelude.h"
M2C_UNK OnSoRemove__FP2SO();                            /* extern */

void OnCid71Remove(void *arg0) {
    OnSoRemove__FP2SO();
    M2C_FIELD(arg0, s32 *, 0x18C) = 0;
}
