#include "common.h"

/* localdecomp:start func_0044AC88 */
extern s32 D_00143950[];
extern f32 D_001D5308;
extern f32 D_001D530C;
extern f32 D_001D5310;
extern f32 D_001D5314;
extern f32 D_001D5318;
extern f32 D_001D531C;
extern s32 D_001D5320;
extern f32 D_001D5324;

void func_0044AC88(s32 a0) {
    if (a0 == 0) {
        D_00143950[0] = 0;
        D_001D5308 = 1.0f;
        D_001D530C = 1.0f;
        D_001D5310 = 1.0f;
        D_001D5314 = 0.0166666675f;
        D_001D5318 = 0.000277777785f;
        D_001D531C = 4.62962953e-06f;
        D_001D5320 = 5;
        D_001D5324 = 0.0166666675f;
    } else {
        D_00143950[0] = 1;
        D_001D5308 = 1.20000005f;
        D_001D530C = 1.44000006f;
        D_001D5310 = 0.833333313f;
        D_001D5314 = 0.0200000014f;
        D_001D5318 = 0.000400000019f;
        D_001D531C = 7.99999998e-06f;
        D_001D5320 = 6;
        D_001D5324 = 0.0199999996f;
    }
}
/* localdecomp:end func_0044AC88 */
