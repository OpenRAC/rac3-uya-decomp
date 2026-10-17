#include "common.h"

extern s32 func_00513A90(s32, s32);
extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 func_00511E28();

extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 D_001DC1F0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E31A8;
extern S_003E31A8 D_001E1660_003E31A8;
s32 func_00513A90(s32 arg0, s32 arg1) {
    s32 *base;
    s32 r;
    void *p;
    void *o;
    S_003E31A8 *q;

    r = 0;
    q = &D_001E1660_003E31A8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_00511BF8(q);
    }
    p = (void *)func_00511368(func_00511E28(base), arg0);
    o = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DC1F0) != 0) ? p : 0;
    if (o != 0) {
        *(s32 *)((u8 *)o + 0x50) = arg1;
        r = 1;
    }
    return r;
}
