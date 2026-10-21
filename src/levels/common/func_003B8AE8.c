#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern s32 D_001D545C;
extern u8 D_001E28C0[];
extern s32 func_004626E8(u8 *);
extern s32 func_004B6920(s32, s32, u8 *, s32);
extern f32 func_0041CDA8(f32, f32);
extern void func_0041CF50(void *, void *);
extern void func_00375BC0(u8 *, void *, void *, s32, s32);
extern void func_003B8E88(u8 *, u8 *);
extern void func_00448A30(u8 *);
extern f32 func_0041C8F0(void *, void *);
extern void func_004536F0(u8 *);

void func_003B8AE8(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    f32 f;
    if (*(u16 *)(o + 0x34) & 0x80) {
        return;
    }
    if (o[0x20] == 0) {
        *(s32 *)(s + 0xA0) = 0;
    }
    if (func_004626E8(*(u8 **)(o + 0xB8)) != 0) {
        if (*(s32 *)(s + 0xA0) == 0) {
            func_004B6920(0, 0, o, 0x1931);
            *(s32 *)(s + 0xA0) = 1;
        }
    } else {
        *(s32 *)(s + 0xA0) = 0;
    }
    *(u128_t *)(o + 0x10) = *(u128_t *)(*(u8 **)(o + 0xB8) + 0x10);
    if (*(f32 *)(o + 0xF8) != func_0041CDA8(*(f32 *)(*(u8 **)(o + 0xB8) + 0xC0), *(f32 *)(*(u8 **)(o + 0xB8) + 0xC4))) {
        *(f32 *)(o + 0xF8) = func_0041CDA8(*(f32 *)(*(u8 **)(o + 0xB8) + 0xC0), *(f32 *)(*(u8 **)(o + 0xB8) + 0xC4));
        func_0041CF50(o + 0xC0, o + 0xF0);
    }
    if (D_001D545C == 11) {
        *(f32 *)(o + 0xF8) = *(f32 *)(*(u8 **)(o + 0xB8) + 0xF8);
        *(f32 *)(o + 0xF0) = *(f32 *)(*(u8 **)(o + 0xB8) + 0xF0);
        *(f32 *)(o + 0xF4) = *(f32 *)(*(u8 **)(o + 0xB8) + 0xF4);
        func_0041CF50(o + 0xC0, o + 0xF0);
    }
    func_00375BC0(s, s + 4, s + 0x10, 0, func_004626E8(*(u8 **)(o + 0xB8)));
    func_003B8E88(o, s);
    func_00448A30(o);
    if (*(f32 *)(s + 0x88) != 0.0f) {
        f = *(f32 *)(s + 0x88) / 5000.0f * 1024.0f;
        *(f32 *)(o + 0xC) += fabsf(f) * 0.55f;
        if (*(f32 *)(o + 0xF0) == 3.1415927f) {
            f = -f;
        }
        *(f32 *)(o + 0x8) += f * 0.5f;
    }
    if (o[0x31] != 0 && func_0041C8F0(D_001E28C0, o + 0x10) < 576.0f) {
        func_004536F0(o);
        o[0x6F] = 0x16;
    }
}
