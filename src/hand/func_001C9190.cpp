// Render thread of the loading screen: waits for the start semaphore, then keeps drawing a pulsing
// (scale + opacity) quad every frame until the frame-end semaphore is signalled.
//
// Matching notes: the function must start directly with the outer `for(;;)` (no pointer locals such as
// `VIFS *builder = &D_002DEA28;` before it). Then the loop header is the first basic block, gcse has no
// pre-header to hoist the `lui`s of D_003D3A3C/D_002DEDBC into (they stay local, which gives the $v1 after the
// WaitSema call), and the inner loop keeps enough insns for loop.c to leave the `m_fCheckCnt = 1` constant alone.
#include "vifs.h"
#include "gifs.h"
struct SEMA {int count,maxCount,initialCount,waitThreads;uint attributes,option;};
struct M2 {float a[8];M2(){}void Identity();};
extern "C" void *func_002333B4(void *,int,int);
inline void M2::Identity(){func_002333B4(this,0,sizeof(*this));a[0]=a[3]=1.0f;}
struct CLOCK {float t,dt,ratio,realRatio,realDt,realT;char pad18[0x24];float frameT,frameDt;ulong tick;};
struct FR {int n0;void *p4;char pad8[0x1C];void *packet;char pad28[8];int flags;};
extern VIFS D_002DEA28;
extern GIFS D_002DEA00;
extern FR *g_pfrmOpen;
extern CLOCK g_clock;
extern float *D_002DD314;
extern int D_003D3A3C,D_003D3A40,D_003D3A44,D_002DEDBC,D_002DEB18;
extern uint D_002BE538;
extern int D_002C10A0,D_002C10A4,D_002C10A8,D_002C10AC;
extern float D_002C10B0,D_002C10B4,D_002C10C0[3],D_002BBB60[2];
extern QW D_002DF260[];
extern "C" int func_00234A60(int);
extern "C" int func_00234A40(int);
extern "C" int func_00234A90(int,SEMA *);
extern "C" float func_00245000(float);
extern "C" void func_001C93E0(GIFS *,M2 *,float);
extern "C" void func_00160A98(void);
extern "C" void MarkClockTick__FP5CLOCKi(CLOCK *,int);
void OpenFrame(void);
static inline void Clamp(float *value,const float *bounds){float low=bounds[0],high=bounds[1];if(*value<low)*value=low;else if(high<*value)*value=high;}
static inline void BeginFrame()
{
    MarkClockTick__FP5CLOCKi(&g_clock,1);
    OpenFrame();
    uchar *pb=D_002DEA28.m_pb;
    g_pfrmOpen->packet=pb;
    D_002DEA28.m_fCheckCnt=1;
    D_002DEA28.AddDmaCnt();
    D_002DEA28.AddVifDirect(0x25,D_002DF260,0);
    D_002DEA28.EndDmaCnt();
}
extern "C" void func_001C9190(void *)
{
    SEMA status;M2 matrix;
    for(;;){
        func_00234A60(D_003D3A3C);
        D_002DEDBC=0;
        for(;;){
            BeginFrame();
            func_00234A90(D_003D3A40,&status);
            if(status.count!=0)break;
            float t=-*D_002DD314+g_clock.frameT;
            float scale=1.0f+D_002C10B0*func_00245000(t*D_002C10B4);
            matrix.Identity();
            matrix.a[0]=D_002C10A0*scale;
            matrix.a[3]=D_002C10A4*scale;
            matrix.a[4]=D_002C10A8;matrix.a[5]=D_002C10AC;
            float alpha=D_002C10C0[0]+t*(D_002C10C0[1]+t*D_002C10C0[2]);
            Clamp(&alpha,D_002BBB60);
            func_001C93E0(&D_002DEA00,&matrix,alpha);
            func_00160A98();D_002BE538++;
        }
        do{g_pfrmOpen->flags&=-2;}while(0);
        func_00160A98();D_002BE538++;
        do {func_00234A90(D_002DEB18,&status);}while(status.count==0);
        func_00234A60(D_003D3A40);
        func_00234A40(D_003D3A44);
    }
}
