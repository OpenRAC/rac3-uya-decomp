#include "common.h"

typedef struct { u8 p0[0x174]; f32 f174; u8 p178[0x2C]; f32 f1A4; f32 f1A8; u8 p1AC[0x2418]; s32 f25C4; u8 p25C8[4]; s32 f25CC; } S_1A4BE0_4EFDD8;
typedef struct { u8 p0[0x10E0]; f32 f10E0; u8 p10E4[4]; f32 f10E8; u8 p10EC[0xA4]; f32 f1190; f32 f1194; f32 f1198; u8 p119C[0xA4]; f32 f1240; } S_2F4580_4EFDD8;
extern S_1A4BE0_4EFDD8 D_001A4BE0;
extern S_2F4580_4EFDD8 D_002F4580;

static inline f32 absf_4EFDD8(f32 x) {
    f32 r;
    __asm__("abs.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

/* localdecomp:start func_004EFDD8 */
void func_004EFDD8(void) {
    s32 m;
    if (D_001A4BE0.f25C4 == 64) {
        f32 a, b;
        a = D_001A4BE0.f1A4 * 9.0f;
        if (a > 0.7f) a = 0.7f;
        else if (a < -0.7f) a = -0.7f;
        a = a * absf_4EFDD8(a) * 1.25f;
        b = D_001A4BE0.f174 / 0.0500000045f;
        D_002F4580.f1240 = -a * 0.2f;
        if (b > 1.0f) b = 1.0f;
        if (b < 0.0f) b = 0.0f;
        D_002F4580.f1240 = D_002F4580.f1240 * b;
        D_002F4580.f10E8 = a;
        D_002F4580.f10E0 = -a * 0.35f;
        D_002F4580.f1198 = a * 1.35f;
        D_002F4580.f1194 = absf_4EFDD8(a) * 0.25f;
        return;
    }
    if (D_001A4BE0.f25C4 == 75) {
        f32 a, b;
        a = D_001A4BE0.f1A8 * 1.6f;
        if (a > 1.25f) a = 1.25f;
        else if (a < -1.25f) a = -1.25f;
        b = -a * 0.52f;
        D_002F4580.f1240 = b;
        if (b > 0.28f) D_002F4580.f1240 = 0.28f;
        else if (b < -0.28f) D_002F4580.f1240 = -0.28f;
        b = a * 1.7f;
        D_002F4580.f1198 = b;
        D_002F4580.f10E8 = a * 0.58f;
        if (b > 0.7f) D_002F4580.f1198 = 0.7f;
        else if (b < -0.7f) D_002F4580.f1198 = -0.7f;
        D_002F4580.f1194 = absf_4EFDD8(a) * 0.2f;
        if (D_002F4580.f1194 > 0.2f) D_002F4580.f1194 = 0.2f;
        else if (D_002F4580.f1194 < -0.2f) D_002F4580.f1194 = -0.2f;
        D_002F4580.f1190 = absf_4EFDD8(a) * 0.16f;
        return;
    }
    m = D_001A4BE0.f25CC;
    if (m == 2 || m == 4) {
        f32 a;
        a = D_001A4BE0.f1A8;
        if (a > 1.4f) a = 1.4f;
        else if (a < -1.4f) a = -1.4f;
        D_002F4580.f10E8 = a * 0.29f;
        D_002F4580.f1198 = a * 0.87f;
    }
}
/* localdecomp:end func_004EFDD8 */
