#include "common.h"
typedef struct { s32 a; s32 b; } S_5138B0;
extern S_5138B0 D_001E1660[];
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_00510C20(s32);
s32 func_005138B0(s32 *a) {
    S_5138B0 *p = D_001E1660;
    s32 q;
    s32 r = 0;
    { S_5138B0 *t; if (p->b != 0) t = p; else t = func_00511BF8(p); q = func_00511E28(t); }
    if (q) { r = 1; *a = func_00510C20(q); }
    return r;
}
