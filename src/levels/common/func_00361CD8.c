#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_004452B0(s32, s32);
extern void func_004625F8(u8 *, u8 *);
extern void func_004513D8(u8 *, s32, s32);
extern void func_00451098(u8 *, s32, s32, s32);

void func_00361CD8(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 *t;
    s32 f;
    s32 x;
    s[0x5E] = 0;
    s[0x60] = 0;
    s[0x5F] = 0;
    __asm__("sq $0, %0" : "=m"(*(u128_t *)(o + 0xF0)));
    t = *(u8 **)(o + 0x24);
    f = *(u16 *)(o + 0x34) & 0xFFBE;
    *(f32 *)(o + 0x2C) = *(f32 *)(t + 0x24);
    *(u128_t *)(o + 0x10) = *(u128_t *)(s + 0x320);
    *(f32 *)(o + 0xF8) = *(f32 *)(s + 0x36C);
    *(u16 *)(o + 0x34) = f;
    f |= *(u16 *)(t + 0x44) & 0x1000;
    *(u16 *)(o + 0x34) = f;
    x = *(s32 *)(t + 0x10);
    f &= 0xFFFD;
    *(u16 *)(o + 0x34) = f;
    *(s32 *)(o + 0x98) = x;
    if (*(u8 **)(s + 0x2FC) == 0) {
        *(u8 **)(s + 0x2FC) = func_004452B0(0x194E, 0x80);
        if (*(u8 **)(s + 0x2FC) != 0) {
            func_004625F8(*(u8 **)(s + 0x2FC), o);
            *(u16 *)(*(u8 **)(s + 0x2FC) + 0x32) = *(u16 *)(o + 0x32);
            *(u8 **)(s + 0x240) = *(u8 **)(s + 0x2FC);
        }
    }
    func_004513D8(o, 0xB, 3);
    if (o[0x43] != 3) {
        func_00451098(o, 3, 0, 0);
    }
    if (*(s32 *)(s + 0x30C) != -1) {
        func_004513D8(o, 9, -1);
    }
}
