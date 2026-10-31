typedef int qword __attribute__((mode(TI)));
float func_001E64C8(void *p, float seed);
void UpdateUbgSgs__FP3UBG(void *p, qword q, void *a, qword *b, qword *c, float *d, float *e, float g);
void func_001E7380(void *p, qword q, void *a, qword *b, qword *c, float *d, float *e, float seed)
{
    UpdateUbgSgs__FP3UBG(p, q, a, b, c, d, e, func_001E64C8(p, seed));
}
