#include "vtable.h"
#include "mat.h"
// Attach an object node, bind its resources, and update its children.
typedef int qword __attribute__((mode(TI)));
struct P;
struct NODE {P *owner;NODE *next;char pad8[8];MATRIX4 matrix;};
struct TREE {int id;TREE *parent;char pad8[8];P *owner;};
struct BIND {int kind,pad4;void *resource;void *begin,*end;P *object;};
struct TABLE {int count;P **objects;int capacity,used;char pad10[0x54];void *states;NODE *nodes;};
struct P {void *resource;char pad4[8];VTE *vt;void *context;char pad14[0x24];float scale;char pad3C[0x14];void *channel;char pad54[0xC];MATRIX4 matrix;char padA0[0x40];TABLE *table;int disabled;NODE *head;int bindCount;BIND *binds;};
struct SW {char pad[0x3F08];TABLE *tables;TREE *root;};
struct DESC {int kind,flags;char pad8[0x20];};
struct STREAM {int flags;unsigned char *cursor;int remaining,consumed;unsigned char *raw;int rawCount,compression,pending,word20;unsigned char *decompressed;int word28,word2C;VTE *vt;void *begin,*end;};
struct WORK {int id;P *found,*child;void *cursor;P *owner;};
extern "C" {
extern SW g_sw;
extern DESC D_002AC880[];
NODE *func_001CADE0(P *,int);
void func_001CAA60(P *,NODE *);
int func_001CA930(P *,NODE *);
int func_001C9940(int,int);
TREE *func_001C99D8(TREE *,int,int *);
int CploFindSwObjects__FP2SWi3OIDP2LOP3PXRiPP2LO(SW *,int,int,P *,void *,int,P **);
STREAM *func_00118480(STREAM *);
void func_00118500(STREAM *,void *,void *,int);
short func_00117D50(STREAM *);
void func_0013E818(P *,DESC *,int,STREAM *);
void AddParent__6CFrameP6CFrame(void *,void *);
void __as__3SPXP1X(void **,void *);
void func_001184B8(STREAM *,int);
}
static inline P *Adjusted(P *p,const VTE &entry){return (P *)((char *)p+entry.delta);}
static inline void Channel(P *p,void *context,void *channel){VTE &v=p->vt[10];((void(*)(P *,void *,void *,int))v.pfn)(Adjusted(p,v),context,channel,0);}
static inline void Matrix(P *p,const MATRIX4 *m){VTE &v=p->vt[37];((void(*)(P *,const MATRIX4 *))v.pfn)(Adjusted(p,v),m);}
static inline void Reset(P *p){VTE &v=p->vt[8];((void(*)(P *))v.pfn)(Adjusted(p,v));}
static inline void Parent(P *p,P *parent){VTE &v=p->vt[26];((void(*)(P *,P *))v.pfn)(Adjusted(p,v),parent);}
static inline void Query(P *p,void **cursor){VTE &v=p->vt[3];((void(*)(P *,int,int,int,void **,int))v.pfn)(Adjusted(p,v),14,0,1,cursor,0);}
extern "C" NODE *func_001CAEC8(P *p,int minimum){
 STREAM stream;
 WORK work;
 NODE *node=func_001CADE0(p,minimum);
 if(!node)return 0;
 if(node->owner)func_001CAA60(node->owner,node);
 node->owner=p;node->next=p->head;p->head=node;
 work.owner=p;
 node->matrix=p->matrix;
 int row=func_001CA930(p,node);
 work.id=func_001C9940(p->table-g_sw.tables,row);
 TREE *tree=func_001C99D8(g_sw.root,1,&work.id);
 for(int i=0;i<p->bindCount;i++){
  BIND *bind=&p->binds[i];
  if(bind->kind==5)continue;
  if(bind->kind==6){work.found=tree->owner;if(!work.found)continue;}
  else if(CploFindSwObjects__FP2SWi3OIDP2LOP3PXRiPP2LO(&g_sw,0xA05,bind->kind,0,tree,1,&work.found)!=1)continue;
  bind->object=work.found;
  func_00118480(&stream);
  func_00118500(&stream,bind->begin,bind->end,0);
  int index;
  while((index=func_00117D50(&stream))>=0){DESC *desc=&D_002AC880[index];func_0013E818(work.found,desc,desc->flags&0x2031,&stream);}
  if(bind->resource && !p->disabled){
   if(work.found->resource)AddParent__6CFrameP6CFrame(bind->resource,work.found->resource);
   __as__3SPXP1X(&work.found->resource,bind->resource);
  }
  func_001184B8(&stream,2);
 }
 for(int i=0;i<p->table->count;i++){
 void **cursor=&work.cursor;
  P *child=p->table->objects[row*p->table->count+i];
  VTE &entry=child->vt[42];
  work.child=child;
  ((void(*)(P *,float))entry.pfn)(Adjusted(child,entry),p->scale);Channel(work.child,p->context,p->channel);Matrix(work.child,&p->matrix);Reset(work.child);Parent(work.child,p);
  work.cursor=&work.child;Query(p,cursor);
  work.cursor=&work.owner;Query(work.child,cursor);
 }
 return node;
}

#define OFF(t,m) ((int)&((t*)0)->m)
