int func_0011D3C0(void);
float GRandInRange__Fff(float gMin, float gMax)
{
    if (gMin == gMax)
        return gMin;
    return gMin + (gMax - gMin) * (float)(func_0011D3C0() % 0x16A1B) * 1.078760305972537e-05f;
}
