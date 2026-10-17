#include "common.h"

extern s32 func_00410120(u8 *, s32);
extern s32 func_004100D8(u8 *, s32);

void func_004C9EF8(u8 *a0, s32 a1, s32 a2, f32 f12, f32 f13) {
    (*(f32 **)a0)[0] = f12;
    (*(f32 **)a0)[1] = f13;
    *(s32 *)(a0 + 408) = a2;
    a0[391] = 0;
    *(u8 **)(a0 + 440) = a0 + 136;
    *(s32 *)(a0 + 420) = a1;
    switch (a1) {
    case 0:
        *(s32 *)(a0 + 436) = func_00410120(a0 + 136, -1);
        break;
    case 1:
        *(s32 *)(a0 + 436) = func_004100D8(a0 + 136, -1);
        break;
    case 2:
        break;
    }
    *(s32 *)(a0 + 400) = 1;
    **(f32 **)(a0 + 4) = 1.0f;
}
