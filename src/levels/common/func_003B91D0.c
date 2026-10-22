#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_004452B0(s32, s32);
extern void func_00375B60(u8 *, u8 *, void *, void *, s32);
extern void func_003B92D0(u8 *, u8 *);
extern void func_0041CF50(void *, void *);

u8 *func_003B91D0(u8 *src) {
    u8 *s3 = *(u8 **)(src + 0x68);
    u8 *o = func_004452B0(0x1930, 0xC0);
    u8 *v;
    f32 *rot;
    if (o != 0) {
        *(u8 **)(o + 0xB8) = src;
        v = *(u8 **)(o + 0x68);
        o[0x30] = src[0x30];
        *(u16 *)(o + 0x32) = *(u16 *)(src + 0x32);
        o[0x31] = src[0x31];
        o[0x20] = 1;
        *(unsigned long *)(o + 0x38) = *(unsigned long *)(src + 0x38);
        *(u128_t *)(o + 0x10) = *(u128_t *)(src + 0x10);
        func_00375B60(o, v, v + 4, v + 0x10, 0);
        func_003B92D0(o, v);
        __asm__("sq $0, %0" : "=m"(*(u128_t *)(o + 0xF0)));
        *(f32 *)(o + 0xF8) = *(f32 *)(src + 0xF8);
        rot = (f32 *)(o + 0xF0);
        if (*(s32 *)(s3 + 8) < 0) {
            *rot = 3.1415927f;
            *(f32 *)(v + 8) = -*(f32 *)(v + 8);
        }
        func_0041CF50(o + 0xC0, rot);
        *(u16 *)(o + 0x34) |= 0x104;
        *(s32 *)(v + 0xA0) = 0;
    }
    return o;
}
