#include "common.h"

/* localdecomp:start func_004C8A80 */
extern s32 D_001E1220;
extern f32 D_001E1224;
extern f32 D_001E1228;

void func_004C8A80(s32 a) {
    f32 x;

    D_001E1220 = a;
    x = 1.0769230127334595f;
    if (a == 0) {
        x = 1.0f;
    }
    D_001E1224 = x;
    x = 0.9f;
    if (a == 0) {
        x = 1.0f;
    }
    D_001E1228 = x;
}
/* localdecomp:end func_004C8A80 */
