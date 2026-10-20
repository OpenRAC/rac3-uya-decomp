#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef union {
    s128 q;
    f32 f[4];
} Vec_004F07E8;

typedef struct {
    u8 pad0[144];
    Vec_004F07E8 f144;
    f32 f160;
    f32 f164;
    u8 pad168[368];
    s16 f536;
    u8 pad538[9130];
    s32 f9668;
    u8 pad9672[4];
    s32 f9676;
    u8 pad9680[36];
    u8 f9716;
} Game_004F07E8;

extern Game_004F07E8 D_001A4BE0;
extern void func_004F0608(void);
extern void func_004455F0(f32 *, f32 *, f32, s32, f32, f32, f32);
extern void func_004EAEC0(f32, f32, f32);

void func_004F07E8(void) {
    Vec_004F07E8 v;
    s32 x;
    s32 m;

    x = D_001A4BE0.f9716;
    if (D_001A4BE0.f536 != 0) {
        x = 1;
    }
    switch (x) {
    case 0:
        m = D_001A4BE0.f9668;
        if ((u32)(m - 36) < 2) {
            break;
        }
        if (D_001A4BE0.f9676 == 17 || m == 121 || m == 48 || m == 44 || m == 43) {
            break;
        }
        v = D_001A4BE0.f144;
        func_004455F0(&v.f[0], &D_001A4BE0.f160, 0.0f, 0, 0.015f, 0.3f, 0.08726647f);
        func_004455F0(&v.f[1], &D_001A4BE0.f164, 0.0f, 0, 0.015f, 0.3f, 0.08726647f);
        func_004EAEC0(D_001A4BE0.f160, D_001A4BE0.f164, 0.0f);
        break;
    case 1:
    case 2:
        func_004F0608();
        break;
    }
}
