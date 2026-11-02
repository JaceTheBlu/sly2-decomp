typedef int qword __attribute__((mode(TI)));
struct P;
struct Endpoint { char pad[8]; struct P *owner,*other; char pad10[0x30]; };
struct N { struct Endpoint e[2]; qword q80; float value; char pad94[8]; int kind; char padA0[0xC]; struct N *next; };
struct L { struct N *first; struct L *next; struct N **back; };
struct G { char pad[0x64]; struct L *groups; struct N *def; };
struct P { char pad[0xEC]; struct G *g; char padF0[0x118]; struct N *best; float t; char pad210[0x20]; qword position; };
extern float D_002A85F4,g_clock;
struct SW;
extern struct SW g_sw;
void func_001F4F10(struct P *);
void FreeSwXpList__FP2SWP2XP(struct SW *,struct N *);
static inline struct P *Other(struct N*n,struct P*p){unsigned different=(unsigned)p^(unsigned)n->e[0].owner;int i=different>0;return ((struct Endpoint *)((char *)n+(i<<6)))->other;}
void func_00204768(struct P *p)
{
    struct N *best;
    struct L *group;
    func_001F4F10(p);
    {
        float value=D_002A85F4;
        group=p->g->groups;
        best=0;
        for(;;){
            struct N *node=group?group->first:p->g->def;
            for(;node;node=node->next){
                if(node->kind==14 && node->value<value){value=node->value;best=node;}
            }
            if(!group)break;
            group=group->next;
        }
    }
    p->best=best;
    if(best){p->t=g_clock;p->position=*(qword *)((char *)best+0x50);}
    {
        struct N *removed=0;
        group=p->g->groups;
        for(;;){
            struct N **link=group?&group->first:&p->g->def;
            struct N *node;
            while((node=*link)!=0){
                if(Other(node,p)==p && node->kind==14 && node!=best){
                    *link=node->next;
                    node->next=removed;
                    removed=node;
                }else link=&node->next;
            }
            if(!group)break;
            *group->back=group->first;
            group=group->next;
        }
        FreeSwXpList__FP2SWP2XP(&g_sw,removed);
    }
}
