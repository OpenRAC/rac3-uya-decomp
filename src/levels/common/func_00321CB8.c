#include "common.h"

typedef struct { u8 b[320]; } E320_321CB8;
typedef struct { u8 b[160]; } E160_321CB8;
typedef struct { u8 x0; u8 x1; u8 pad[238]; } E240_321CB8;

extern s32 D_001E1830;
extern s32 D_001DBCE0;
extern u8 D_00142607[];
extern E240_321CB8 D_002C5640[];
extern E320_321CB8 D_00276B20[];
extern E160_321CB8 D_00276DA0[];
extern f32 func_004408C0(f32, f32);
extern void func_003220F8(void *, s32, s32, u32, f32, f32, u32, s32, void *, s32, s32);

void func_00321CB8(u8 *a0) {
    s32 half;
    s32 i;
    f32 f;

    s32 t;
    half = D_001E1830 / 2;
    t = *(s32 *)(*(u8 **)(a0 + 104) + 68);
    D_001DBCE0 |= 1;
    if (t != 0) {
        for (i = 0; i < 2; i++) {
            f = func_004408C0(0.025f, 0.03f);
            func_003220F8(&D_00276B20[i], 20, half, 0x7F7F7F, f, func_004408C0(1.5f, 2.5f), 0xFF2020, 0, a0, 0, 1);
        }
        if (D_001E1830 >= 20 && (D_002C5640 + D_00142607[0])->x1 >= 2) {
            for (i = 0; i < 2; i++) {
                f = func_004408C0(0.015f, 0.02f);
                func_003220F8(&D_00276DA0[i], 10, half, 0xFF7F7F7F, f, func_004408C0(1.2f, 1.8f), 0xFFFF2020, 0, a0, 1, 0);
            }
        }
    }
}
