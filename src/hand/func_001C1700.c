#include "vu0.h"
typedef int qword __attribute__((mode(TI)));
union U {qword q;unsigned int words[4];};
struct C {qword x,z;int version;int xmin,xmax,zmin,zmax;};
struct S {char pad[0xFC];int count,active;void*xs,*zs;void**objects;int pad110,version;};
void func_001C1440(struct S*,struct C*);
void func_001C15F8(void*,int*,int*,qword*,float,float);
static inline qword And(qword a,qword b){qword r;__asm__("pand %0,%1,%2":"=r"(r):"r"(a),"r"(b));return r;}
int func_001C1700(struct S*p,struct C*c,qword a,qword b,int max,void**out){
 struct C local;
 union U mask,copy;
 qword hi,lo;
 int i,n;
 float hx,lx;
 if(!p->active)return 0;
 if(!c){c=&local;c->version=-1;}
 if(c->version!=p->version)func_001C1440(p,c);
 lo=QwMin(a,b);hi=QwMax(a,b);
 func_001C15F8(p->xs,&c->xmin,&c->xmax,&c->x,GetX(lo),GetX(hi));
 func_001C15F8(p->zs,&c->zmin,&c->zmax,&c->z,GetY(lo),GetY(hi));
 copy.q=And(c->x,c->z);mask=copy;
 {void**cursor=out;
 for(i=0,n=0;i<p->count;i++){
  if(mask.words[i/32]&(1<<(i%32))){
   if(max<n)break;
   *cursor++=p->objects[i];n++;
  }
 }
 }
 c->version=p->version;
 return n;
}
