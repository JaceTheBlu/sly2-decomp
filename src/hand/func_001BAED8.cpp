struct S {
    char pad[0x16C]; int a, b;
    void Action() __asm__("func_001BB400");
};
struct G;
extern G g_sw;
typedef void (S::*PMF)();
extern "C" void func_00149AB8(G *, S *, PMF, int);
extern "C" void func_001BAED8(S *p, int a, int b)
{
    p->b = b;
    p->a = a;
    func_00149AB8(&g_sw, p, &S::Action, 0);
}
