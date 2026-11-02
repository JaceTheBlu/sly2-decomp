#include "common.h"
struct S { char pad[0x148]; ulong a:26; int b:1; ulong c:37; };
struct G;
extern struct G g_sw;
void func_00134320(struct G *, struct S *);
void func_001F6918(struct S *p, int f) { p->b = f; func_00134320(&g_sw, p); }
