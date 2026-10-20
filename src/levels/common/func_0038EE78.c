#include "common.h"
typedef int s128 __attribute__((mode(TI)));
extern u8 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_004C4A18(u8 *, s32, f32, f32, f32);
extern void func_00439610(u8 *);
u8 *func_0038EE78(s32 a0, s128 *pos, s128 *rot) {
    u8 *m;
    u8 *v;
    s32 c;
    m = func_00435E70(6282, 128);
    if (m != 0) {
        m[32] = 0;
        c = 255;
        *(s16 *)(m + 50) = c;
        m[48] = c;
        v = *(u8 **)(m + 104);
        *(s128 *)(m + 16) = *pos;
        *(s128 *)v = *rot;
        m[35] = 40;
        *(f32 *)(m + 44) = 0.0165f;
        *(f32 *)(v + 16) = func_004408C0(0.0523598827f, 0.104719765f);
        *(f32 *)(v + 20) = func_004408C0(0.0523598827f, 0.104719765f);
        *(s32 *)(v + 48) = a0;
        *(s32 *)(v + 24) = 0;
        *(s32 *)(v + 52) = func_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
        func_00439610(m);
    }
    return m;
}
