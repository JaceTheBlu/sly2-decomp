#include "clock.h"
extern CLOCK g_clock;
struct EMITTER { char pad[0xF0]; int k; int c; char pad2[0x148 - 0xF8]; float tUnpause; };
int FPausedEmitter(EMITTER *pemitter)
{
    if (g_clock.t < pemitter->tUnpause)
        return 1;
    switch (pemitter->k) {
    case 0:
    case 1:
        if (pemitter->c == 0)
            return 1;
    }
    return 0;
}
