#include "m2c_prelude.h"
M2C_UNK func_00130658(s32);                         /* extern */
M2C_UNK func_001EECD0(s32);                         /* extern */
M2C_UNK OnSoRemove__FP2SO();                            /* extern */
M2C_UNK func_00208540(s32, M2C_UNK);                /* extern */

void OnStepguardRemove__FP9STEPGUARD(s32 arg0) {
    OnSoRemove__FP2SO();
    func_00208540(arg0, 0);
    func_001EECD0(arg0 + 0x26C);
    func_00130658(arg0 + 0x34C);
}
