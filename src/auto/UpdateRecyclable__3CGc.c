#include "m2c_prelude.h"
M2C_UNK Flush__4DMAS(M2C_UNK *);                   /* extern */
M2C_UNK func_001D9878(M2C_UNK *);                   /* extern */
extern M2C_UNK D_002DEA00;
extern M2C_UNK D_002DEA28;
extern M2C_UNK D_003D9E80;
extern M2C_UNK D_003DA0F0;
extern M2C_UNK D_003DA150;

void UpdateRecyclable__3CGc(void) {
    func_001D9878(&D_003D9E80);
    func_001D9878(&D_003DA0F0);
    func_001D9878(&D_003DA150);
    Flush__4DMAS(&D_002DEA00);
    Flush__4DMAS(&D_002DEA28);
}
