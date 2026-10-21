#include "common.h"

typedef int Q_3A63F8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A63F8;

extern f32 func_003EF258(void *, void *);
extern void func_003EF3A0(void *, void *, f32);
extern void func_004243F8(void *, s32, s32);
extern void func_00424ED8(s32, s32);
extern void func_00435C60(void *, s32);
extern s32 func_00435C80(void *);
extern void func_004891A0(s32, s32, void *);
extern u8 D_001A4C60[];

void func_003A63F8(u8 *a0) {
    V4_3A63F8 a, b, c;
    Q_3A63F8 q1, q2;
    u8 t;

    if (a0[0x20] == 0) {
        if (a0[0x21] != 0xFF) {
            t = a0[0xBC];
            if (t != 0) {
                if (t != 2) {
                    func_004891A0(0, 0, a0);
                    func_00424ED8(a0[0x21], 2);
                }
                func_004243F8(a0, 1, -1);
                func_00435C60(a0, 1);
            } else if (func_00435C80(a0) != 0) {
                func_004243F8(a0, 1, -1);
            }
        } else if (func_003EF258(a0 + 0x10, D_001A4C60) < 7.0f) {
            func_004891A0(0, 0, a0);
            func_004243F8(a0, 1, -1);
            func_00435C60(a0, 1);
        }
    }
    if (a0[0x20] == 1) {
        (*(u16 *)(a0 + 0x96))++;
        func_003EF3A0(&a, a0 + 0xE0, 0.058333337f);
        func_003EF3A0(&b, a0 + 0xC0, -0.058333337f);
        __asm__ volatile("lqc2 %0, %1" : "=j"(q1) : "m"(a));
        __asm__ volatile("lqc2 %0, %1" : "=j"(q2) : "m"(*(V4_3A63F8 *)(a0 + 0x10)));
        __asm__ volatile("vadd.xyz %0, %0, %1" : "+j"(q2) : "j"(q1));
        __asm__ volatile("lqc2 %0, %1" : "=j"(q1) : "m"(b));
        __asm__ volatile("sqc2 %1, %0" : "=m"(c) : "j"(q1));
        __asm__ volatile("sqc2 %1, %0" : "=m"(*(V4_3A63F8 *)(a0 + 0x10)) : "j"(q2));
        __asm__ volatile("lqc2 %0, %1" : "=j"(q1) : "m"(*(V4_3A63F8 *)(a0 + 0x10)));
        __asm__ volatile("lqc2 %0, %1" : "=j"(q2) : "m"(c));
        __asm__ volatile("vadd.xyz %0, %0, %1" : "+j"(q1) : "j"(q2));
        __asm__ volatile("sqc2 %1, %0" : "=m"(*(V4_3A63F8 *)(a0 + 0x10)) : "j"(q1));
        if (*(u16 *)(a0 + 0x96) >= 0x1F) {
            func_004243F8(a0, 2, -1);
        }
    }
}
