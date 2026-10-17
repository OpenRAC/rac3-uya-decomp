#include "common.h"
typedef struct {
    f32 f0;
    f32 f4;
    s32 w8;
    s32 wC;
    f32 f10;
} T_005CAFF8;
extern s32 func_0058EFB8(u8 *);
extern void func_005C2288(u8 *);
extern s32 func_00590438(s32, s32, f32);
void func_005CAFF8(u8 *a0) {
    T_005CAFF8 *t;
    f32 f;
    if (func_0058EFB8(a0 + 10) != 0) {
        func_005C2288(a0);
        return;
    }
    t = (T_005CAFF8 *)(a0 + 32);
    f = (f32)*(s16 *)(a0 + 10) * t->f10;
    *(s32 *)(a0 + 4) = func_00590438(t->wC, t->w8, f);
    *(f32 *)(a0 + 12) = ((*(f32 *)(a0 + 32) - t->f4) * f + t->f4) * 210000.0f;
}
