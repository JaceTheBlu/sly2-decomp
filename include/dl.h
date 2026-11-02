/* Doubly-linked lists (P2/dl).  A DL threads through its elements: each element holds a DLE (next/prev) at byte
   offset ibDle.  A DLI is an iterator registered on a list so removals during iteration stay safe. */
#ifndef DL_H
#define DL_H

struct DL
{
    void *head;         /* first element */
    void *tail;         /* last element */
    int ibDle;          /* offset of the DLE inside an element */
};

struct DLE
{
    void *next;
    void *prev;
};

struct DLI
{
    struct DL *m_pdl;           /* list being iterated */
    void **m_ppv;               /* points at the link to the current element */
    int m_ibDle;
    struct DLI *m_pdliNext;     /* next live iterator (g_pdliFirst chain) */
};

#ifndef __cplusplus
typedef struct DL DL;
typedef struct DLE DLE;
typedef struct DLI DLI;
#endif

#endif /* DL_H */
