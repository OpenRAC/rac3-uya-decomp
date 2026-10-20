#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_00513DC8;

extern S_00513DC8 D_001E1660;
extern s32 D_001DC250;
extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern void func_0051C3F8(void *, f32);
extern void func_0051C408(void *, s32);
extern void func_0051C418(void *, s32);

s32 func_00513DC8(s32 a0, s32 a1, s32 a2, f32 f) {
    S_00513DC8 *q = &D_001E1660;
    void *base;
    void *p;
    s32 r = 0;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = func_00511BF8();
    }
    p = (void *)func_00511368(func_00511E28(base), a0);
    if (p == 0 || (*(s32 (**)(void *, s32))(*(u8 **)((u8 *)p + 8) + 0x10))(p, D_001DC250) == 0) {
        p = 0;
    }
    if (p != 0) {
        func_0051C3F8(p, f);
        r = 1;
        func_0051C408(p, a1);
        func_0051C418(p, a2);
    }
    return r;
}
