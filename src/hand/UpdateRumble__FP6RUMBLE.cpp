typedef unsigned char byte;
/* Sly 2 order differs from Sly 1: (rums == Stop) yields 1 */
enum RUMS { RUMS_Nil = -1, RUMS_Dead = 0, RUMS_Idle = 1, RUMS_Rumble = 2, RUMS_Stop = 3, RUMS_Kill = 4 };
struct RUMINS { byte fHighSpeedMotor; byte bLowSpeedMotor; float dt; };
struct RUMPAT { int crumins; RUMINS arumins[32]; };
struct RUMBLE {
    int nPort;
    int nSlot;
    RUMS rums;
    RUMPAT *prumpat;
    int irumins;
    float dtRumble;
    float dtRumins;
};
struct CLOCK { float a[20]; };
extern CLOCK g_clock;
extern "C" int func_00243870(int, int, byte *);
void SetRumbleRums(RUMBLE *prumble, RUMS rums);
void StopRumbleActuators(RUMBLE *prumble);
void UpdateRumble(RUMBLE *prumble)
{
    byte abShockDirect[6];
    float dtReal = g_clock.a[16];

    switch (prumble->rums) {
    case RUMS_Rumble:
        if (prumble->dtRumble > 0.0f) {
            prumble->dtRumins -= dtReal;
            if (prumble->dtRumins <= 0.0f) {
                if (++prumble->irumins >= prumble->prumpat->crumins)
                    prumble->irumins = 0;
                abShockDirect[0] = prumble->prumpat->arumins[prumble->irumins].fHighSpeedMotor;
                abShockDirect[1] = prumble->prumpat->arumins[prumble->irumins].bLowSpeedMotor;
                func_00243870(prumble->nPort, prumble->nSlot, abShockDirect);
                prumble->dtRumins = prumble->prumpat->arumins[prumble->irumins].dt;
            }
            prumble->dtRumble -= dtReal;
        } else {
            SetRumbleRums(prumble, RUMS_Stop);
        }
        break;
    case RUMS_Stop:
    case RUMS_Kill:
        if (prumble->dtRumins > 0.0f) {
            StopRumbleActuators(prumble);
            prumble->dtRumins -= dtReal;
        } else {
            SetRumbleRums(prumble, (prumble->rums == RUMS_Stop) ? RUMS_Idle : RUMS_Dead);
        }
        break;
    default:
        return;
    }
}
