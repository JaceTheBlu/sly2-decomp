struct CProg { int m_cRetry; int m_nRemain; int m_nTarget; int m_nMax; char m_fActive; char pad[0x3f]; int m_n50; };
void End__5CProg(struct CProg *p) { p->m_cRetry = 0; p->m_n50 = 0; p->m_nMax = 0; p->m_nTarget = 0; p->m_nRemain = 0; p->m_fActive = 0; }
