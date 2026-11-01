#include "vu0.h"
// func_002048C8: breadth-first polygon adjacency search. MATCH.
typedef int qword __attribute__((mode(TI)));
typedef unsigned short ushort;
union V {qword q;float f[4];};
struct E {ushort vertices[2],faces[2];struct E *next0,*next1;};
struct POLY {float normal[3];int unknown;struct E *head0,*head1;int flags,pad;};
struct GEOM {char pad94[0x94];qword *positions;int unknown;struct POLY *polygons;};
struct P {char pad210[0x210];float height;char pad214[0x34];float previous;};
void func_0011EE08(qword,qword,qword,qword *,float *,float *);
int func_002048C8(struct P *p,qword position,struct GEOM *g,struct POLY *first)
{
    struct POLY *queue[32];
    union V closest;
    float distance;
    int count=1,current=0;
    float delta=p->height-p->previous;
    float limit=delta*1.45f;
    float maximumNormal=0.7f;
    queue[0]=first;
    do {
        struct POLY *poly=queue[current];
        int side;
        for(side=0;side<2;side++){
            struct E *edge;
            if(!side)edge=poly->head0;else edge=poly->head1;
            while(edge){
                float z=GetZ(position);
                func_0011EE08(position,g->positions[edge->vertices[0]],g->positions[edge->vertices[1]],&closest.q,0,&distance);
                if(limit<distance)goto next;
                if(z+delta<closest.f[2])goto next;
                {
                    struct POLY *neighbor=&g->polygons[edge->faces[1-side]];
                    int j;struct POLY **pp;
                    if(maximumNormal<neighbor->normal[2])return 1;
                    for(j=0,pp=queue;;pp++,j++){
                        if(j>=count){
                            if((unsigned)count<32)queue[count++]=neighbor;
                            break;
                        }
                        if(neighbor==*pp)break;
                    }
                }
            next:
                if(!side)edge=edge->next0;else edge=edge->next1;
            }
        }
    }while(++current<count);
    return 0;
}
