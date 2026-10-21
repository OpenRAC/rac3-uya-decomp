#include "common.h"

typedef int s128_00378620 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00378620;

extern void func_00378710(void *a0, void *a1);
extern void func_004135E0(void *fn, void *a1);
extern s32 func_0041D9D8(V4_00378620 *v, f32 r);
extern s32 func_004626E8(void *a0);
extern void func_003788F8(void);
extern void func_00378D78(void);
extern s32 D_001D545C;

void func_00378620(u8 *a0) {
    V4_00378620 v;
    u8 *s1;
    f32 r;

    s1 = *(u8 **)(a0 + 0x68);
    if (*(u16 *)(a0 + 0x34) & 0x80) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        func_00378710(a0, s1);
        return;
    case 1:
        break;
    default:
        return;
    }
    *(s128_00378620 *)&v = *(s128_00378620 *)(a0 + 0x10);
    v.w = 4.0f;
    r = 40.0f;
    if (D_001D545C == 0xB) {
        r = 255.0f;
    }
    if (func_0041D9D8(&v, r) == -1) {
        return;
    }
    if (func_004626E8(a0) != 0) {
        func_004135E0(func_003788F8, a0);
        return;
    }
    if (*(s32 *)(s1 + 4) != 6) {
        func_004135E0(func_00378D78, a0);
    }
}
