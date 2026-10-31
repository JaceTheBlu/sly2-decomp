#include "vifs.h"
extern "C" void *func_002333B4(void *pv, int n, int cb);
extern "C" void EnsureVu1Code__FP4VIFSPvT1(VIFS *pvifs, void *pvStart, void *pvEnd);
extern char D_0025E680[];
extern char D_00262320[];
extern char D_00000000[];
extern "C" void func_0016E1A8(VIFS *pvifs)
{
    uint *pun;
    EnsureVu1Code__FP4VIFSPvT1(pvifs, D_0025E680, D_00262320);
    pvifs->AddDmaCnt();
    pvifs->UnpackHelper(UPK_V4_16, 11, 10, 0, &pun);
    func_002333B4(pun, 0, 0x58);
    pvifs->AddVifMscal(D_00000000);
    pvifs->EndDmaCnt();
}
