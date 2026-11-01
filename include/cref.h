/* Splice script value (P2/splice/ref): a tag kind plus the value it describes.
   C++ sources get the class (constructor sets the kind to -1, destructor calls Decref); C sources, and C++ sources
   that define CREF_PLAIN first because they handle CRef as plain data, get the bare layout. */
#ifndef CREF_H
#define CREF_H

#if defined(__cplusplus) && !defined(CREF_PLAIN)
#include "vu0.h"

class CRef
{
public:
    int m_tagk;                 /* TAGK: kind of value */
    union
    {
        int m_tag;              /* integer / bool / symbol id / kind-specific word */
        void *m_p;              /* object, pair, proc, vector, matrix... */
        float m_g;              /* float */
    };

    CRef() { m_tagk = -1; }
    CRef(int tagk) { InitTag(tagk); }
    CRef(const CRef &r);
    ~CRef() { Decref(); }
    CRef &operator=(const CRef &r);
    CRef &operator=(float g);
    CRef &operator=(int n);
    CRef &operator=(bool f);
    CRef &operator=(void *pv);
    CRef &operator=(vu0_qword q);
    void Decref();
    void InitTag(int tagk);
};

#else

struct CRef
{
    int m_tagk;
    union
    {
        int m_tag;
        void *m_p;
        float m_g;
    };
};
#ifndef __cplusplus
typedef struct CRef CRef;
#endif

#endif

#endif /* CREF_H */
