/* Matched: plain search loop, array pointer cached, key re-read each iteration. */
struct MSG{int kind;};
struct OWNER;
struct S{struct MSG msg;int word4;int x8;int*xC;int pad[3];unsigned flags;};
extern struct OWNER D_003D9ED0;
void func_001AFB88(struct OWNER *g,struct MSG *s);
#define FIELD_OFFSET(t,m) ((unsigned int)&(((t*)0x10000)->m)-0x10000)
typedef char Offset_0[FIELD_OFFSET(struct MSG,kind)==0?1:-1];
typedef char Offset_1[FIELD_OFFSET(struct S,msg)==0?1:-1];
typedef char Offset_2[FIELD_OFFSET(struct S,word4)==4?1:-1];
typedef char Offset_3[FIELD_OFFSET(struct S,x8)==8?1:-1];
typedef char Offset_4[FIELD_OFFSET(struct S,xC)==12?1:-1];
typedef char Offset_5[FIELD_OFFSET(struct S,flags)==28?1:-1];
typedef char Size_0[sizeof(struct MSG)==4?1:-1];
typedef char Size_1[sizeof(struct S)==32?1:-1];
typedef char Size_2[sizeof(int)==4?1:-1];
typedef char Size_3[sizeof(unsigned)==4?1:-1];
typedef char Size_4[sizeof(void*)==4?1:-1];
void func_001AFFC0(struct S *s)
{
    int i;int *a=s->xC;
    for(i=0;i<s->x8;i++){
        if(s->msg.kind==a[i]){i++;s->msg.kind=a[i%s->x8];break;}
    }
    func_001AFB88(&D_003D9ED0,&s->msg);
    s->flags |= 2;
}
