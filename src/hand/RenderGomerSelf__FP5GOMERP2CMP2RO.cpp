struct GOMER { char pad[0xE78]; int fE78; };
struct CM;
struct RO;
extern "C" void InitStepguard__FP9STEPGUARD(GOMER *pgomer, CM *pcm, RO *pro);
void RenderGomerSelf(GOMER *pgomer, CM *pcm, RO *pro)
{
    InitStepguard__FP9STEPGUARD(pgomer, pcm, pro);
    pgomer->fE78 = 1;
}
