#include "common.h"

/* localdecomp:start func_005139B0 */
extern s32 func_005139B0(s32, s32);
extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 D_001DC0F8;
extern s32 func_00511E28();

extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern u8 func_00515BA0_003E30C8[];
extern s32 D_001DC0F8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E30C8;
extern S_003E30C8 D_001E1660_003E30C8;
extern u8 D_0026DD58[];
s32 func_005139B0(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E30C8 *q;

    r = 0;
    q = &D_001E1660_003E30C8;
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
        cb = (void *)((void *(*)(void *, s32))func_00515BA0_003E30C8)(D_0026DD58, t);
        if (cb != 0) {
            r = cb(p, arg1);
        } else {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_005139B0 */
