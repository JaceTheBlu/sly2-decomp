struct CLOCK { float t; float dt; };
extern CLOCK D_002DDED0 asm("D_002DDED0");
enum EYESS { EYESS_Nil = -1, EYESS_Open = 0, EYESS_Closing = 1, EYESS_Closed = 2, EYESS_Opening = 3 };
struct SAI { int a; };
struct EYES { char pad[0x1C]; int cframe; char pad1[0x34 - 0x20]; SAI sai; char pad2[0x50 - 0x38]; float dtBlink; float dtOpenMin; float dtOpenMax; float uDoubleBlink;
    int pad60; EYESS eyess; float tEyess; float dtOpen; float dframe; float iframe; float uOpen; };
extern "C" int func_0011A1E8(SAI *psai);
extern "C" void SetSaiIframe__FP3SAIi(EYES *p, int iframe);
void SetEyesEyess(EYES *peyes, EYESS eyess);
extern "C" void UpdateEyes__FP4EYESf(EYES *peyes);
void UpdateEyes__FP4EYESf(EYES *peyes)
{
    if (func_0011A1E8(&peyes->sai) || peyes->cframe < 2)
        return;

    EYESS eyessNext = peyes->eyess;
    switch (peyes->eyess)
    {
    case EYESS_Open:
        if (D_002DDED0.t - peyes->tEyess >= peyes->dtOpen)
            eyessNext = EYESS_Closing;
        break;
    case EYESS_Closing:
    {
        float dframe = peyes->dframe * D_002DDED0.dt;
        peyes->iframe += dframe;
        if (peyes->iframe >= (float)peyes->cframe)
        {
            peyes->iframe -= dframe;
            eyessNext = ((int)peyes->iframe == peyes->cframe - 1) ? EYESS_Closed : EYESS_Opening;
        }
        break;
    }
    case EYESS_Closed:
        if (peyes->uOpen < 1.0f)
            eyessNext = EYESS_Opening;
        break;
    case EYESS_Opening:
        peyes->iframe -= peyes->dframe * D_002DDED0.dt;
        if (peyes->iframe <= peyes->cframe * peyes->uOpen)
            eyessNext = EYESS_Open;
        break;
    }

    SetEyesEyess(peyes, eyessNext);
    SetSaiIframe__FP3SAIi(peyes, (int)peyes->iframe);
}
