struct MSG { int cb; int nKind; };
void *PvAllocSwClearImpl__FP7SWALLOC(struct MSG *p);
void *__builtin_new(int cb) { struct MSG m; m.cb = cb; m.nKind = 0x10; return PvAllocSwClearImpl__FP7SWALLOC(&m); }
