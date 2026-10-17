#include "common.h"

extern s32 func_00513EA8(s32, f32, f32);
extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 func_00511E28();

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3330;
extern S_003E3330 D_001E1660_003E3330[];
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_00511368();
extern s32 D_001DC220;
extern void func_0051B900(void *p, f32, f32);
s32 func_00513EA8(s32 arg0, f32 fparg0, f32 fparg1) {
    S_003E3330 *q;
    S_003E3330 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001E1660_003E3330;
    if (p->x4) q = p;
    else q = func_00511BF8(p);
    t = (void *)func_00511368(func_00511E28(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001DC220) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_0051B900(v, fparg0, fparg1);
    }
    return r;
}
