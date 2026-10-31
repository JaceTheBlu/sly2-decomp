extern float D_002A4FF8;
void func_001A37D0(float a, float b, float c, float d, float *pa, float *pb);
struct P { char pad[0x240]; float g240, g244, g248; };
void SetCmLookAt__FP2CMfPv(struct P *p, float *af, float f)
{
    if (f == D_002A4FF8) f = 1.0f;
    func_001A37D0(1.0f, 4080.0f, p->g244 / p->g240, (1.0f - p->g248 * f) * 4080.0f, &af[0], &af[1]);
    af[0] += 8417280.0f;
    af[2] = p->g240;
    af[3] = af[0] + 8192.0f;
}
