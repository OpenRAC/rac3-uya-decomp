#include "common.h"

/* localdecomp:start func_004FB758 */
typedef struct {
    u8 pad0[152];
    float f98;
    u8 pad1[400 - 156];
    u8 sub190[16];
    float f1A0;
    u8 pad2[5172 - 420];
    s16 h1434;
    u8 pad3;
    u8 b1437;
    u8 pad4[5808 - 5176];
    s32 mode;
    u8 pad5[9716 - 5812];
    u8 b25F4;
} Veldin1A4BE0;

extern Veldin1A4BE0 D_001A4BE0;
extern s32 func_0045D358(s32, s32, s32, s32);
extern void func_004EAA78(s32, float);
extern float func_004F1018(void *, s32);
extern float func_0040CF10(float, float);
extern float func_0040CFB0(float, float);
s32 func_004FB758(void) {
    s32 r = 2;
    s32 c;
    float a;
    float k;

    if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.mode == 1 && func_0045D358(40, 2, 0, 0) != 0)) {
        c = D_001A4BE0.b1437;
        if (c == 0) {
            r = 0;
        } else if (c == 3) {
            r = 3;
        } else if (c == 2) {
            r = 2;
        } else {
            r = 1;
        }
    } else {
        func_004EAA78(0, 1.0f);
        if (D_001A4BE0.b25F4 != 0) {
            a = func_004F1018(D_001A4BE0.sub190, 0);
        } else {
            a = func_0040CF10(D_001A4BE0.f1A0, D_001A4BE0.f98);
        }
        k = 0.7853982f;
        if (func_0040CFB0(a, 3.1415927f) < k) {
            r = 3;
        } else if (func_0040CFB0(a, -1.5707964f) < k) {
            r = 1;
        } else if (func_0040CFB0(a, 1.5707964f) < k) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_004FB758 */
