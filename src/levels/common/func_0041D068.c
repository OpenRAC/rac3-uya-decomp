#include "common.h"

extern u8 *D_001DCCCC;
extern u8 *D_0034F4AC[];
extern void func_00475E40(void *a0, s32 a1, s32 a2);
extern f32 func_00453BC8(f32 a0, f32 a1);

void func_0041D068(u8 *a0) {
    u8 state = a0[32];
    s32 *p = *(s32 **)(a0 + 104);
    f32 target;
    f32 cur;
    s32 idx;
    s32 v;
    s32 j;

    switch (state) {
    case 0:
        a0[48] = 255;
        if (p[2] != 0) {
            *(f32 *)(a0 + 240) = -0.43633232f;
        }
        func_00475E40(a0, 1, -1);
        break;
    case 1:
        idx = p[0];
        if (idx < 0) {
            return;
        }
        j = *(s32 *)(*(u8 **)(D_001DCCCC + (idx << 8) + 104) + 44);
        if (j < 0) {
            return;
        }
        v = *(s32 *)(D_0034F4AC[0] + (j << 2) + 168);
        target = 0.0f;
        if (p[1] == v) {
            target = -0.43633232f;
        }
        if (v == -1) {
            return;
        }
        cur = *(f32 *)(a0 + 240);
        if (cur == target) {
            return;
        }
        if (cur < target) {
            *(f32 *)(a0 + 240) = func_00453BC8(cur, 0.0014544411f);
        } else {
            *(f32 *)(a0 + 240) = func_00453BC8(cur, -0.0014544411f);
        }
        if (0.0f < *(f32 *)(a0 + 240)) {
            *(f32 *)(a0 + 240) = 0.0f;
        }
        if (*(f32 *)(a0 + 240) < -0.43633232f) {
            *(f32 *)(a0 + 240) = -0.43633232f;
        }
        break;
    }
}
