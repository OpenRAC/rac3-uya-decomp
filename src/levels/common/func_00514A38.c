#include "common.h"

/* localdecomp:start func_00514A38 */
extern s32 func_00514A38(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00512480(s32, f32, f32);
extern s32 func_00513548(s32, f32, f32);
extern s32 func_005130C8(s32, s32);
extern s32 func_005131A0(s32, s32);
extern s32 func_005130C8();
extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 D_001DC1F0;

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3BD0;
extern S_003E3BD0 D_001E1660_003E3BD0[];
extern void *func_00511BF8();
extern s32 func_00511E28();
extern s32 func_00511368();
extern s32 func_00476AF0(s32);
extern s32 D_001DC1F0;
s32 func_00514A38(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    S_003E3BD0 *p;
    S_003E3BD0 *q;
    void *t;
    void *v;
    s32 ok;
    s32 u;
    ok = func_00476AF0(a);
    u = func_00512480(a, x, y) != 0;
    if (!ok) u = 0;
    ok = u;
    u = func_005130C8(a, b) != 0;
    ok = ok & u;
    u = func_00513548(a, z, w) != 0;
    ok = ok & u;
    u = func_005131A0(a, c) != 0;
    ok = ok & u;
    p = D_001E1660_003E3BD0;
    if (p->x4) q = p;
    else q = func_00511BF8(p);
    t = (void *)func_00511368(func_00511E28(q), a);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001DC1F0) != 0) ? t : 0;
    *(s16 *)((u8 *)v + 0x4A) = 0;
    return ok;
}
/* localdecomp:end func_00514A38 */
