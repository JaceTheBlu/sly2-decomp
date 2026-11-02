#include "m2c_prelude.h"
extern f32 g_clock;

void PauseEmitter__FP7EMITTERf(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x148) = (f32) (g_clock + fparg0);
}
