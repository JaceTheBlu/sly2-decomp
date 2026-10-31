struct S { char pad[0x194]; void *p194; void *p198; };
int func_00131968(void *p);
int GetSmaCur__FP3SMA(void *p);
int func_001F07C8(void *p);
int func_0017F550(struct S *p) { if (p->p194) return func_00131968(p->p194); { int f = 1; if (p->p198) f = GetSmaCur__FP3SMA(p->p198) == func_001F07C8(p->p198); return f; } }
