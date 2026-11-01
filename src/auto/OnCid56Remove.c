#include "m2c_prelude.h"
M2C_UNK func_00130658(s32);                         /* extern */
M2C_UNK func_001EECD0(s32);                         /* extern */
M2C_UNK OnCid48Remove();                            /* extern */
M2C_UNK func_00208540(s32, M2C_UNK);                /* extern */

void OnCid56Remove(s32 arg0) {
    OnCid48Remove();
    func_00208540(arg0, 0);
    func_001EECD0(arg0 + 0x26C);
    func_00130658(arg0 + 0x34C);
}
