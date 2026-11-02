struct X { char pad[0xF0]; int fF0; int fF4; int fF8; };
class CSave {
public:
    X *m_p0;
    X *m_p4;
    int m_n8;
    int m_nC;
    CSave(X *px, int nF4, int nF8)
    {
        m_p4 = px;
        m_p0 = 0;
        m_n8 = px->fF4;
        px->fF4 = nF4;
        m_nC = m_p4->fF8;
        m_p4->fF8 = nF8;
    }
    ~CSave()
    {
        if (m_p0) {
            m_p0->fF0 = m_n8;
            m_p0->fF4 = m_nC;
        }
        if (m_p4) {
            m_p4->fF4 = m_n8;
            m_p4->fF8 = m_nC;
        }
    }
};
struct G { char pad[0x3B10]; X *f3b10; };
extern G g_sw;
extern "C" int func_00164018(X *px);
extern "C" void func_00163CE0(X *px);
extern "C" void func_00163D18(X *px);
extern "C" void func_00163C28(X *px)
{
    if (func_00164018(px)) return;
    if (g_sw.f3b10) {
        CSave save(g_sw.f3b10, px->fF4, px->fF8);
        func_00163CE0(g_sw.f3b10);
    }
    func_00163D18(px);
}
