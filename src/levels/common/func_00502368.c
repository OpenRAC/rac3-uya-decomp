#include "common.h"

/* localdecomp:start func_00502368 */
typedef struct {
    u8 p0[0x1A0];
    s32 w1A0;
} S_00502368;

typedef struct {
    u8 p0[0x1434];
    s16 h1434;
    u8 p1436[0x16B0 - 0x1436];
    s32 w16B0;
    u8 p16B4[0x2838 - 0x16B4];
    f32 f2838;
} G_00502368;

extern s32 func_0045E3B8(s32, s32);
extern s32 func_0045D358(s32, s32, void *, s32);
extern s32 func_004FB720(void);
extern s32 func_0045D3E8(s32, s32, s32, s32, s32);
extern s32 func_004FB758(void);
extern void func_004FC518(s32, s32);
extern S_00502368 *D_001D52FC;
extern G_00502368 D_001A4BE0;

s32 func_00502368(s32 a, s32 b) {
    u8 buf[16];
    s32 n;
    if (func_0045D358(func_0045E3B8(64, 0), a, buf, 0) == 0) {
        return 0;
    }
    n = func_004FB720();
    if ((D_001D52FC->w1A0 & func_0045E3B8(8, 0)) && n > 0
        && func_0045D3E8(func_0045E3B8(64, 0), 0x1F000, a + n, n, 0) != 0) {
        func_004FC518(11, 1);
        return 1;
    }
    if ((D_001A4BE0.h1434 != 0 || (D_001A4BE0.w16B0 == 1 && func_0045D358(40, 2, 0, 0) != 0))
        && D_001A4BE0.f2838 > 0.9f && func_004FB758() != 2) {
        func_004FC518(11, 1);
        return 1;
    }
    if (b != 0) {
        return 0;
    }
    func_004FC518(7, 1);
    return 1;
}
/* localdecomp:end func_00502368 */
