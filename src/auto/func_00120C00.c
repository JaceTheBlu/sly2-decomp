#include "m2c_prelude.h"
extern s128 D_002A2DD0;
extern M2C_UNK D_002BBB70;
extern M2C_UNK D_004520A8;

s32 func_00120C00(s32 arg0, s32 arg1, void *arg2) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(M2C_FIELD(arg2, void **, 4), void **, 0x10);
    if (temp_a1 == NULL) {
        SetTag__4CRef4TAGK(arg0, 0);
    } else {
        __4CRefP4NODE(arg0, temp_a1);
    }
    return arg0;
}
