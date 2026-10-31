#include "m2c_prelude.h"
f32 *PeaFindAsegLabel__FP4ASEG3OID();                               /* extern */

f32 TFindAsegLabel__FP4ASEG3OID(void) {
    f32 *temp_v0;
    f32 var_f0;

    temp_v0 = PeaFindAsegLabel__FP4ASEG3OID();
    var_f0 = 0.0f;
    if (temp_v0 != NULL) {
        var_f0 = *temp_v0;
    }
    return var_f0;
}
