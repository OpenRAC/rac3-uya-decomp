#include "common.h"

/* localdecomp:start func_005D8BA0 */
extern f32 D_001D7F70[4];
extern s32 D_001D7F80[4];

void func_005D8BA0(s32 i, f32 x) {
    f32 *p = &D_001D7F70[i];
    *p = 1.0f - x;
    if (*p > 1.0f) {
        *p = 1.0f;
    }
    if (*p < 0.0f) {
        *p = 0.0f;
    }
    D_001D7F80[i] = 2;
}
/* localdecomp:end func_005D8BA0 */
