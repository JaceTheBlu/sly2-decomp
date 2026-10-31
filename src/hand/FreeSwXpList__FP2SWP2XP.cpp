struct SLOTHEAP { int a[4]; };
struct XP { char pad[0xAC]; XP *pxpNextSw; };
struct SW { char pad[0x3D40]; SLOTHEAP slotheapXp; };
void FreeSlotheapPv(SLOTHEAP *psh, void *pv) __asm__("FreeSlotheapPv__FP8SLOTHEAPPv");
void FreeSwXpList(SW *psw, XP *pxp)
{
    while (pxp) {
        XP *pxpNext = pxp->pxpNextSw;
        FreeSlotheapPv(&psw->slotheapXp, pxp);
        pxp = pxpNext;
    }
}
