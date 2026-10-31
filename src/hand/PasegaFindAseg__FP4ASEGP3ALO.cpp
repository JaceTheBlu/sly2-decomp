#include "dl.h"
struct ALO;
struct ASEGA { char pad[0x18]; ALO *palo; char pad2[0x10]; ASEGA *pasegaNext; };
struct ASEG { char pad[0x50]; ASEGA *pasegaFirst; };
ASEGA *PasegaFindAseg(ASEG *paseg, ALO *palo)
{
    DLI dli;
    ASEGA *p;
    for (p = paseg->pasegaFirst; p; p = p->pasegaNext)
        if (p->palo == palo) return p;
    return 0;
}
