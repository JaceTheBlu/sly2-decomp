#include "m2c_prelude.h"
s128 func_001A6F00(s32, void *, s128);              /* extern */
M2C_UNK LoadPoFromBrx();                            /* extern */
M2C_UNK func_001F8300(void *);                      /* extern */
extern s128 D_002A2DD0;

void LoadStepguardFromBrx__FP9STEPGUARDP18CBinaryInputStream(void *arg0) {
    LoadPoFromBrx();
    M2C_FIELD(arg0, s128 *, 0x240) = func_001A6F00(M2C_FIELD(arg0, s32 *, 0x10), arg0, D_002A2DD0);
    func_001F8300(arg0);
}
