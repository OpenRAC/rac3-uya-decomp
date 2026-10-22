#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A6298;
typedef struct {
    u8 pad0[0x10];
    V4_3A6298 pos;
    u8 f20;
    u8 f21;
    u8 pad22[0x96 - 0x22];
    u16 f96;
    u8 pad98[0xBC - 0x98];
    u8 fBC;
    u8 padBD[0xC0 - 0xBD];
    V4_3A6298 vC0;
    u8 padD0[0x10];
    V4_3A6298 vE0;
} O_3A6298;
extern u8 D_001A4C60[];
extern void func_004243F8(O_3A6298 *, s32, s32);
extern void func_00435C60(O_3A6298 *, s32);
extern s32 func_00435C80(O_3A6298 *);
extern f32 func_003EF258(V4_3A6298 *, void *);
extern void func_003EF3A0(V4_3A6298 *, V4_3A6298 *, f32);

void func_003A6298(O_3A6298 *o) {
    V4_3A6298 a, b, c;

    if (o->f20 == 0) {
        if (o->f21 != 0xFF) {
            if (o->fBC != 0) {
                func_004243F8(o, 1, -1);
                func_00435C60(o, 1);
            } else if (func_00435C80(o) != 0) {
                func_004243F8(o, 1, -1);
            }
        } else if (func_003EF258(&o->pos, D_001A4C60) < 7.0f) {
            func_004243F8(o, 1, -1);
            func_00435C60(o, 1);
        }
    }
    if (o->f20 == 1) {
        o->f96++;
        func_003EF3A0(&a, &o->vE0, 0.058333337f);
        func_003EF3A0(&b, &o->vC0, -0.058333337f);
        __asm__ __volatile__(
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "lqc2 $vf1, %2\n"
            "sqc2 $vf1, %3\n"
            "sqc2 $vf2, %1\n"
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %3\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %1\n"
            : "+m"(a), "+m"(o->pos), "+m"(b), "+m"(c) : : "memory");
        if (o->f96 >= 0x1F) {
            func_004243F8(o, 2, -1);
        }
    }
}
