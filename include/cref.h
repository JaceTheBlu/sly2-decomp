/* Splice script value (P2/splice/ref): a tag kind plus the value it describes.  The C++ sources use the full class
   with its methods; this is the plain layout for code that only moves values around. */
#ifndef CREF_H
#define CREF_H

struct CRef
{
    int m_tagk;                 /* TAGK: kind of value */
    union
    {
        int m_tag;              /* integer / bool / symbol id / kind-specific word */
        void *m_p;              /* object, pair, proc, vector, matrix... */
        float m_g;              /* float */
    };
};

#ifndef __cplusplus
typedef struct CRef CRef;
#endif

#endif /* CREF_H */
