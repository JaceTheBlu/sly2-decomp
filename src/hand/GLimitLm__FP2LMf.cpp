#include "util.h"

float GLimitLm(LM *plm, float g)
{
    if (g < plm->gMin) {
        return plm->gMin;
    }
    if (g > plm->gMax) {
        return plm->gMax;
    }
    return g;
}
