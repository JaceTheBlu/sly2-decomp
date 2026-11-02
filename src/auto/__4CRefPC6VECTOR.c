#include "m2c_prelude.h"
s128 *func_0011CCC0(M2C_UNK *);                     /* extern */
extern M2C_UNK D_00452188;

void *__4CRefPC6VECTOR(void *arg0, s128 *arg1) {
    s128 *temp_v0;

    M2C_FIELD(arg0, s32 *, 0) = 0x1A;
    temp_v0 = func_0011CCC0(&D_00452188);
    M2C_FIELD(temp_v0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s128 **, 4) = temp_v0;
    M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x10) + 1);
    *M2C_FIELD(arg0, s128 **, 4) = *arg1;
    return arg0;
}
