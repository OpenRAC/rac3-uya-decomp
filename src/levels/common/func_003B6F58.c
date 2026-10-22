#include "common.h"

/* localdecomp:start func_003B6F58 */
extern void func_003B7020(void *, s32, s32, s32, f32, f32, f32);
extern s32 D_001DE5CC;
extern s32 D_001DE5D0;
extern f32 D_001DE5DC;
extern f32 D_001DE5E0;
extern f32 D_001DE5EC;
extern f32 D_001DE5F0;
extern s32 D_001DE5F4;
extern s32 D_001DE5F8;
extern f32 D_001DE5FC;
extern f32 D_001DE600;
extern f32 D_001DE608;
extern f32 D_001DE60C;
extern u8 D_002A3270[];

void func_003B6F58(void *arg0) {
    f32 f;
    u8 *s2;

    f = D_001DE5DC - D_001DE5E0;
    s2 = *(u8 **)((u8 *)arg0 + 0x68);
    D_001DE5DC = f;
    if (f <= -8.0f) {
        D_001DE5DC = f + 8.0f;
    }
    func_003B7020(D_002A3270 + *(s32 *)(s2 + 0x38) * 0x280, D_001DE5CC, D_001DE5D0, *(s32 *)(s2 + 0x2C) - 2, D_001DE5EC, D_001DE5F0, D_001DE608);
    func_003B7020(D_002A3270 + 0x140 + *(s32 *)(s2 + 0x38) * 0x280, D_001DE5F4, D_001DE5F8, *(s32 *)(s2 + 0x2C), D_001DE5FC, D_001DE600, D_001DE60C);
}
/* localdecomp:end func_003B6F58 */
