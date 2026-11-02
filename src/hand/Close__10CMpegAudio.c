struct S { int a; char pad[0x9C]; int xa0; int xa4; };
void func_00232F60(void);
void func_002321E8(int n, int v);
void func_00232468(unsigned int m);
void Close__10CMpegAudio(struct S *p)
{
    p->a = 0;
    func_00232F60();
    func_002321E8(2, p->xa0);
    func_002321E8(0x10, p->xa4);
    func_00232468(0xFFFFFFFF);
}
