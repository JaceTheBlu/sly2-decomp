struct SAVE {
    int a;
    int b;
    int n8;
    int nC;
    float g10;
    float g14;
    int n18;
    int n1C;
    int n20;
};
extern "C" void func_00243CB0(void);
extern "C" void InitMemcard__FP7MEMCARD(void *);
void InitSave(SAVE *psave, int a, int b)
{
    func_00243CB0();
    InitMemcard__FP7MEMCARD((char *)psave + 0xFD5C);
    psave->a = a;
    psave->b = b;
    psave->n8 = -1;
    psave->nC = 0;
    psave->g10 = psave->g14 = 0.0f;
    psave->n18 = 0;
    psave->n1C = 0;
    psave->n20 = 0;
}
