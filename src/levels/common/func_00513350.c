#include "common.h"

extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 D_001DC0F8;
extern s32 func_00511E28();

extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern u8 func_00515CA8_003E2618[];
extern s32 D_001DC0F8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2618;
extern S_003E2618 D_001E1660_003E2618;
extern u8 D_0026E028[];
s32 func_00513350(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2618 *q;

    r = 0;
    q = &D_001E1660_003E2618;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_00511BF8(q);
    }
    p = (void *)func_00511368(func_00511E28(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DC0F8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_00515CA8_003E2618)(D_0026E028, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
