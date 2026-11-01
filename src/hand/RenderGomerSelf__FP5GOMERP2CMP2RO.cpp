struct GOMER { char pad[0xE78]; int fE78; };
struct CM;
struct RO;
extern "C" void InitCid56(GOMER *pgomer, CM *pcm, RO *pro);
void RenderGomerSelf(GOMER *pgomer, CM *pcm, RO *pro)
{
    InitCid56(pgomer, pcm, pro);
    pgomer->fE78 = 1;
}
