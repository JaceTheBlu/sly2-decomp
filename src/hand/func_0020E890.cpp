// Load the pending world and restore actor and view state.
typedef unsigned int uint;
struct HEADER {int words[16];};
struct REQUEST {int flags;HEADER header;int objectId,objectKey;};
struct KEY {int name,tag,kind;char data[0x104];};
struct VT {short delta,unused;void *function;};
struct WIDGET {char pad0[0x58];int shown;};
struct ACTOR {char pad0[0xC];VT *vtable;char pad10[8];int tag;char pad1C[0xF10];WIDGET *widget;};
struct CONTEXT {char pad0[0x148];int count;struct {int tag,value;} objects[1];};
struct SW {char pad0[0x3BF0];int pending;REQUEST request;HEADER current;int unused3C80,unused3C84,objectId,objectKey;char pad3C90[0x228];int actorCount;ACTOR *actors[1];char pad3EC0[0x8AC];float resumeTime;char pad4770[0x20];};
struct FRAME;
struct STREAM;
struct REF;
extern char g_clock[],g_cm[],D_002DEB30[],D_002F7980[],D_002F66B0[],D_00443740[],D_002E1E88[];
extern char D_002A8A88[];
extern ACTOR *D_002E1E40,*D_002DD5BC,*D_002F7900;
extern SW g_sw;
extern "C" {
void func_00160E68(int);
FRAME *func_001AE478(FRAME *);
void _$_18CBinaryInputStream(FRAME *,int);
void func_001C2A78(int);
void func_00258248(KEY *);
STREAM *__3OBJiPvi(STREAM *,int,void *,int);
int func_00184D60(STREAM *,KEY *);
void func_00184950(STREAM *,int);
void SetDecompress__18CBinaryInputStreamiPUc(STREAM *,int,void *);
void func_00184CA0(STREAM *);
void func_0020E068(SW *);
void func_0014D068(void *);
void func_00187078(int);
void *func_002333B4(void *,int,uint);
SW *func_0020D9D0(SW *);
int func_001B3B08(void *);
void func_0014D6D8(void *);
void func_0020E180(SW *);
void LoadSwFromBrx(SW *,STREAM *);
void func_00184CF0(STREAM *);
void func_0020E740(SW *);
void func_001618F8(SW *,float);
void func_0014C258(void);
CONTEXT *func_00227FE8(SW *,int,int);
void func_00228750(CONTEXT *);
ACTOR *func_001C4840(SW *);
ACTOR *func_001C4A48(SW *);
void func_00129EC8(REF *);
ACTOR *PloFindSwObject__FP2SWi3OIDP2LO(SW *,int,int,void *);
int FIsBasicDerivedFrom__FP5BASIC3CID(ACTOR *,int);
int func_001C4080(ACTOR *);
int _IppoFindPo__FP2PO(void);
void func_00212A70(WIDGET *,int);
void func_0014D478(void *);
void func_0014D8C0(void *);
void func_001619A0(void *,int,void *);
void func_001C2BA8(int);
void func_0022B420(void *);
void func_001A4E80(void *);
}
struct FRAME {FRAME(){}~FRAME(){}};
struct STREAM {int flags;char pad4[0x2C];void *vtable;int spoolBytes;char *spool;int fileHandle,position,writePosition,capacity,input,secondaryHandle,state54,state58,state5C,state60;};
struct REF {int tag,value;REF(const REF &);~REF(){func_00129EC8(this);}};
extern "C" REF func_001D8A38(const char *,...);
static inline float Time(){return *(float *)g_clock;}
static inline int Same(const HEADER *a,const HEADER *b){if(a==b)return true;if(!b)return false;return (a->words[2]^a->words[14])==(b->words[2]^b->words[14]);}
static inline int SetKey(KEY *key,const HEADER *header){if(!header)return false;int c=header->words[0],a=header->words[13],d=header->words[15],b=header->words[1];key->kind=2;key->tag=b^d;key->name=(c^a)+0xCA0;return key->tag!=0;}
static inline void Activate(ACTOR *actor){VT *entry=&actor->vtable[8];((void (*)(void *))entry->function)((char *)actor+entry->delta);}
static inline void Enable(ACTOR *actor,int mode){VT *entry=&actor->vtable[79];((void (*)(void *,int))entry->function)((char *)actor+entry->delta,mode);}
static inline void Attach(ACTOR *actor,CONTEXT *context){VT *entry=&actor->vtable[38];((void (*)(void *,CONTEXT *))entry->function)((char *)actor+entry->delta,context);}
static inline void Hide(ACTOR *actor){VT *entry=&actor->vtable[9];((void (*)(void *))entry->function)((char *)actor+entry->delta);}
static inline int NonZero(int v){int r; __asm__("sltu %0,$zero,%1":"=r"(r):"r"(v));return r;}
static inline STREAM *StreamHome(STREAM *home){register STREAM *result __asm__("$4");__asm__("la %0,%a1":"=r"(result):"p"(home));return result;}
extern "C" void func_0020E890(SW *p)
{
    if(!p->pending)return;
    func_00160E68(1);
    REQUEST request=p->request;
    REQUEST *destination=&p->request;
    p->pending=0;
    float resume;
    if(request.flags&0xCD)resume=0.0f;
    else{float remaining=p->resumeTime-Time();resume=remaining>0.0f?remaining:0.0f;}
    FRAME frame;
    FRAME *scope=&frame;
    func_001AE478(scope);
    func_001C2A78(2);
    KEY key;
    KEY *keyPointer=&key;
    keyPointer->kind=2;
    func_00258248(keyPointer);
    int hasFile=NonZero(request.header.words[1]^request.header.words[15]);
    if(hasFile&&!SetKey(&key,&request.header)){_$_18CBinaryInputStream(scope,2);return;}
    HEADER *current=&p->current; const HEADER *requested=&request.header; int changed=!Same(requested,current);
    STREAM stream;
    register STREAM *argument __asm__("$4")=StreamHome(&stream);
    register STREAM *reader __asm__("$21");
    __asm__("daddu %0,%1,$zero":"=r"(reader):"r"(argument));
    __3OBJiPvi(argument,0xD8000,D_002F7980,0);
    if(hasFile&&!func_00184D60(reader,&key)){func_00184950(reader,2);_$_18CBinaryInputStream(scope,2);return;}
    SetDecompress__18CBinaryInputStreamiPUc(reader,0x4000,(void *)0x70000000);
    func_00184CA0(reader);
    func_0020E068(p);
    func_0014D068(g_clock);
    func_00187078(8);
    func_002333B4(&g_sw,0,0x4790);
    func_002333B4(&g_sw,0,0x4790);
    func_0020D9D0(&g_sw);
    if(func_001B3B08(D_002F66B0))changed=1;
    func_0014D6D8(g_cm);
    p->current=request.header;
    *destination=request;
    func_0020E180(p);
    if(hasFile){LoadSwFromBrx(p,reader);func_00184CF0(reader);}
    func_0020E740(p);
    if(resume>0.0f)func_001618F8(p,resume);
    if(changed||(p->request.flags&0x40))func_0014C258();
    CONTEXT *context=func_00227FE8(p,p->request.objectId,p->request.objectKey);
    if(context){func_00228750(context);p->objectId=p->request.objectId;p->objectKey=p->request.objectKey;}
    if(!func_001C4840(p)&&!func_001C4A48(p)&&p->actorCount>0){
        ACTOR *selected=0;
        int actorId;
        {REF value=func_001D8A38(D_002A8A88,0);actorId=value.value;}
        if(actorId!=-1)selected=PloFindSwObject__FP2SWi3OIDP2LO(p,5,actorId,0);
        if(!selected)selected=D_002E1E40;
        if(!selected)selected=D_002DD5BC;
        if(!selected)selected=D_002F7900;
        if(selected){
            Activate(selected);
            Enable(selected,1);
            if(context){
                int i;
                for(i=0;i<context->count;i++)if(context->objects[i].tag==selected->tag)break;
                if(i>=context->count)Attach(selected,context);
            }
            for(int i=0;i<p->actorCount;i++){
                ACTOR *actor=p->actors[i];
                if(actor!=selected&&FIsBasicDerivedFrom__FP5BASIC3CID(actor,0x34)&&!func_001C4080(actor))Hide(actor);
            }
        }
    }
    if(!_IppoFindPo__FP2PO()){
        ACTOR *actor=func_001C4840(p);
        if(actor&&FIsBasicDerivedFrom__FP5BASIC3CID(actor,0x34)&&actor->widget&&!actor->widget->shown)func_00212A70(actor->widget,1);
    }
    func_0014D478(g_cm);
    func_0014D8C0(g_cm);
    func_001619A0(D_002DEB30,5,0);
    func_001C2BA8(2);
    func_0022B420(D_00443740);
    if(!hasFile)func_001A4E80(D_002E1E88);
    func_00184950(reader,2);
    _$_18CBinaryInputStream(scope,2);
}
