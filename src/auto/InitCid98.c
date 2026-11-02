#include "m2c_prelude.h"
M2C_UNK InitSo__FP2SO();                            /* extern */
M2C_UNK func_001F7918(s32, M2C_UNK, M2C_UNK);       /* extern */

void InitCid98(s32 arg0) {
    InitSo__FP2SO();
    func_001F7918(arg0, 0x03FFFFFF, 8);
    func_001F7918(arg0, 0x80001, 0);
}
