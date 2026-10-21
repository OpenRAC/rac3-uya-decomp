#include "common.h"

typedef int Q_3B1F50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B1F50;

extern void func_00431888(void *, void *, s32, s32, f32);
extern u8 *func_004186B0(s32, s32);
extern void func_003EF3A0(void *, void *, f32);
extern void func_00435B90(void *, void *);
extern void func_003F0178(f32, f32);
extern void func_003EF8E8(void *, void *);
extern void func_004240B8(void *, s32, s32, s32);
extern u8 D_001D558C;

void func_003B1F50(u8 *a0) {
    V4_3B1F50 v;
    Q_3B1F50 qa, qb;
    u8 *s0 = *(u8 **)(a0 + 0x68);
    u8 *o;

    if (a0[0x31] != 0) {
        func_00431888(a0, s0, 0x80909090, 0x80404040, 0.081448704f);
    }
    if (*(s32 *)(s0 + 4) != 0 && a0[0x20] == 0 && D_001D558C != 0) {
        a0[0x20] = 1;
        o = func_004186B0(0x1BBE, 0x80);
        func_003EF3A0(&v, a0 + 0xC0, -3.0f);
        func_00435B90(o, a0);
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(V4_3B1F50 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3B1F50 *)(o + 0x10)) : "j"(qa));
        func_003F0178(*(f32 *)(o + 0xF8), 3.1415927f);
        func_003EF8E8(o + 0xC0, o + 0xF0);
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 4.0f;
        if (a0[0x43] != 3) {
            func_004240B8(a0, 3, 0, 0);
        }
    }
}
