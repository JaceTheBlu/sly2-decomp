typedef int qword __attribute__((mode(TI)));
struct WRE { int wrek; int pad[3]; qword a; qword b; int pad2[2]; float c; char pad3[0x4C]; float d; char pad4[0x44]; };
struct WR { char pad[0x50]; float f50; int cwre; int c58; int pad5; WRE awre[8]; char pad6[0x6E0 - 0x60 - 0xD0 * 8]; int c6E0; };
extern qword D_002A2DB0, g_normalZ;
void AddWrBendWarp(WR *pwr)
{
    WRE *pwre = &pwr->awre[pwr->cwre++];
    pwr->c6E0++;
    pwre->wrek = 1;
    pwre->a = D_002A2DB0;
    pwre->b = g_normalZ;
    pwre->c = 0.5f;
    pwre->d = 0.5f;
    pwr->c58++;
}
