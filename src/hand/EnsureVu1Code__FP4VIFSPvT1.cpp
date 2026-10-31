#include "dmas.h"
extern "C" void EnsureVu1Code__FP4VIFSPvT1(DMAS *pdmas, QW *pqwStart, QW *pqwEnd)
{
    pdmas->AddDmaRefs((uint)((char *)pqwEnd - (char *)pqwStart + 15) >> 4, pqwStart);
}
