#include "m2c_prelude.h"
s32 PloNew__F3CIDP2SO3OIDi(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PostStepguardLoad__FP9STEPGUARD();                            /* extern */

void PostCid63Load(void *arg0) {
    PostStepguardLoad__FP9STEPGUARD();
    M2C_FIELD(arg0, s32 *, 0x1010) = PloNew__F3CIDP2SO3OIDi(3, 0, 0x62B, -1);
}
