#include "util.h"
#include "gifs.h"
struct PACKET {int count;QW*data;};
struct TEXTURE;
struct ENTRY {char unknown0[4];uchar kind,flags;char unknown6[6];RGBA color,secondary;char unknown14[4];TEXTURE*texture;int unknown1C;PACKET*packets;char unknown24[8];};
extern int D_003DCFE8;
extern ENTRY *D_003DCFEC;
extern uint D_002DE18C;
extern "C" void func_001EA750(TEXTURE*,int,GIFS*);
extern "C" void func_001EB960();
static inline ulong ColorWord(const RGBA&color,const ENTRY*entry){ulong value=(ulong)color.bRed|((ulong)color.bGreen<<8)|((ulong)color.bBlue<<16);if(entry->flags&2)return (value|((ulong)color.bAlpha<<24))|(1UL<<32);return value|(1UL<<32);}
static inline void Pair(GIFS&q,int first,ulong regs){q.AddPrimBulk(first,0,4,regs,0);q.AddPrimBulk(first+1,0,4,regs,0);}
static inline void Packed(GIFS&q){q.AddPrimPack(0,1,0xE);}
static inline void End(GIFS&q){q.GIFS::EndPrim(1);q.EndDmaCnt();}
union BLEND_WORD {ulong value;struct {ulong first:2;ulong second:2;ulong third:2;ulong fourth:2;ulong remaining:56;} fields;};
static inline ulong Alpha(ENTRY*e){BLEND_WORD word;word.value=0;word.fields.second=(e->flags&1)?2UL:1UL;word.fields.fourth=1;return word.value;}
#define OFF(t,m) ((unsigned int)&((t*)0)->m)
static inline ulong TestWordOr(uint base,ulong bits){
 register ulong result __asm__("$6");register uint input __asm__("$5")=base;register ulong mask __asm__("$2")=bits;
 __asm__("or %0,%1,%2":"=r"(result):"r"(input),"r"(mask));return result;
}
static inline ulong TestBaseAndKind(const ENTRY *entry,uint flags,uint &depthKind,uint &flags4){
 register uint rawKind __asm__("$2")=entry->kind;
 register uint retained __asm__("$3")=0x7EB;
 register ulong base __asm__("$5")=0x7E1;
 register uint marked __asm__("$4")=flags;
 __asm__("andi %1,%1,4\n\tmovz %0,%2,%3\n\tdaddu %2,%3,$zero"
  :"+r"(base),"+r"(marked),"+r"(retained):"r"(rawKind));
 depthKind=retained;flags4=marked;return base;
}
void func_001EB960(){
 int i;
 for(i=0;i<D_003DCFE8;i++){
  ENTRY*e=D_003DCFEC+i;
  PACKET*p=e->packets;
  switch(e->kind){
  case 0:case 4:case 5:case 6:{
   GIFS q;
   q.AllocStatic(p->count,p->data);
   Pair(q,0x7C,0x4F12);
   Packed(q);
   func_001EA750(e->texture,0,&q);
   uint capturedFlags=e->flags;
   if(capturedFlags&0x20){
    ulong test=(capturedFlags&4)?0x13001UL:0x11001UL;
    test|=e->kind?0x20000UL:0x60000UL;
    q.PackAD(0x47,test);q.PackAD(0x42,0);
   }else if(capturedFlags&0x10){
    uint depthKind,flags4;
    ulong testBase=TestBaseAndKind(e,capturedFlags,depthKind,flags4);
    ulong test=(ulong)testBase|0x11000UL;
    if(flags4)test=(ulong)testBase|0x13000UL;
    test|=depthKind?0x20000UL:0x60000UL;
    q.PackAD(0x47,test);q.PackAD(0x42,((ulong)(e->flags&1)<<3)|1);
   }else if(capturedFlags&0x80){
    q.PackAD(0x47,0x77000);q.PackAD(0x42,0x54);
   }else{
    uint depthKind,flags4;
    ulong testBase=TestBaseAndKind(e,capturedFlags,depthKind,flags4);
    ulong test=(ulong)testBase|0x11000UL;
    if(flags4)test=(ulong)testBase|0x13000UL;
    test|=depthKind?0x20000UL:0x60000UL;
    q.PackAD(0x47,test);q.PackAD(0x42,Alpha(e));
   }
   q.PackAD(0x3D,(ulong)D_002DE18C);End(q);
   break;
  }
  case 3:{
   GIFS q;RGBA rounded,color;
   q.AllocStatic(p->count,p->data);
   if(e->flags&2){
    Pair(q,0x7C,0x4F12);Packed(q);
    func_001EA750(e->texture,0,&q);
    q.PackAD(0x47,0x71001);q.PackAD(0x42,Alpha(e));
    q.PackAD(0x3D,(ulong)D_002DE18C);
   }else{
    Pair(q,0x4C,0x4FFF);Packed(q);
    q.PackAD(0x47,0x71001);q.PackAD(0x42,0x6A);
    q.PackAD(1,(1UL<<32)|0x20);
   }
   End(q);++p;ulong one=1,two=2,mask=0x40;q.Clear();
   q.AllocStatic(p->count,p->data);++p;
   Pair(q,0x4C,0x4FFF);Packed(q);
   q.PackAD(0x47,0x71001);q.PackAD(0x42,0x6A);
   q.PackAD(1,(1UL<<32)|0x80002000UL);End(q);q.Clear();
   q.AllocStatic(p->count,p->data);++p;
   Pair(q,0x6C,0x4FFF);q.AddPrimPack(0,5,0x12EEE);
   q.PackAD(0x47,0x75001);{
 register uint blendFlags __asm__("$2");register ulong blendSource __asm__("$6");
 __asm__("lbu %0,%2\n\taddiu %1,$zero,1":"=r"(blendFlags),"=r"(blendSource):"m"(e->flags));
 register int blendRegister __asm__("$5");
 __asm__("addiu %0,$zero,0x42\n\tandi %1,%1,1":"=r"(blendRegister),"+r"(blendFlags));
 if(blendFlags)blendSource=two;
 q.PackAD(blendRegister,(blendSource<<2)|mask);
 }
   q.PackAD(0x3D,(ulong)D_002DE18C);
   q.PackSTQ(0.f,0.f,1.f);
   {

    rounded.bRed=(e->color.bRed+1)>>1;rounded.bGreen=(e->color.bGreen+1)>>1;
    rounded.bBlue=(e->color.bBlue+1)>>1;rounded.bAlpha=(e->color.bAlpha+1)>>1;
    q.PackRGBA(*(uint*)&rounded);
   }
   End(q);q.Clear();
   q.AllocStatic(p->count,p->data);
   q.AddPrimBulk(0x4D,0,1,4,0);
   {
    color=e->secondary;
    Packed(q);if(e->flags&1)one=two;q.PackAD(0x42,(one<<2)|mask);
    q.PackAD(1,ColorWord(color,e));
   }
   End(q);break;
  }
  case 2:{
   GIFS q;
   q.AllocStatic(p->count,p->data);
   q.AddGifTag(0x44,0,2,0x41,1);q.AddGifTag(0x45,0,2,0x41,1);
   Packed(q);
   if(e->flags&8)q.PackAD(0x47,0x71001);else q.PackAD(0x47,0x75001);
   q.PackAD(0x42,(1UL<<39)|0x62);++p;End(q);q.Clear();
   q.AllocStatic(p->count,p->data);
   q.AddGifTag(0x44,0,2,0x41,1);q.AddGifTag(0x45,0,2,0x41,1);
   Packed(q);
   if(e->flags&8)q.PackAD(0x47,0x31001);else q.PackAD(0x47,0x35001);
   q.PackAD(0x42,(1UL<<39)|0x68);End(q);break;
  }
  case 1:{
   GIFS q;
   q.AllocStatic(p->count,p->data);
   Pair(q,0x7C,0x4F12);Packed(q);func_001EA750(e->texture,1,&q);
   if(e->flags&0x80){
    q.PackAD(0x47,0x77000);q.PackAD(0x42,0x54);
   }else{
    q.PackAD(0x47,(e->flags&4)?0x737EB:0x717EB);q.PackAD(0x42,Alpha(e));
   }
   q.PackAD(0x3D,(ulong)D_002DE18C);++p;End(q);q.Clear();
   q.AllocStatic(p->count,p->data);
   Pair(q,0x7C,0x41F2);Packed(q);func_001EA750(e->texture,0,&q);
   if(e->flags&0x80){
    q.PackAD(0x47,0x57000);q.PackAD(0x42,0x58);
   }else{
    q.PackAD(0x47,0x51001);q.PackAD(0x42,0x48);
   }
   q.PackAD(0x3D,0);End(q);break;
  }
  case 7:{
   GIFS q;
   if(!(e->flags&0x20)){
    q.AllocStatic(p->count,p->data);++p;
    Pair(q,0x7C,0x41F2);Packed(q);func_001EA750(e->texture,2,&q);
    q.PackAD(0x47,0x5000D);q.PackAD(0x42,0x40);q.PackAD(0x3D,0);
    End(q);q.Clear();
   }
   q.AllocStatic(p->count,p->data);++p;
   Pair(q,0x7C,0x4F12);Packed(q);func_001EA750(e->texture,1,&q);
   q.PackAD(0x47,0x53001);q.PackAD(0x42,Alpha(e));q.PackAD(0x3D,(ulong)D_002DE18C);
   End(q);q.Clear();
   q.AllocStatic(p->count,p->data);
   Pair(q,0x7C,0x41F2);Packed(q);func_001EA750(e->texture,0,&q);
   q.PackAD(0x47,0x53001);q.PackAD(0x42,0x48);q.PackAD(0x3D,0);End(q);break;
  }
  }
 }
}
