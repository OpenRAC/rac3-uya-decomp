#include "common.h"

/* localdecomp:start func_004BE138 */
extern s32 D_001E0FE0;
extern s32 D_001E0FD8;
extern f32 D_001E0FE8;
extern f32 D_001E0FEC;
extern s32 D_001E0FF0;
extern s32 D_001E0FF4[];

s32 func_004BE138(s32 a, s32 b, s32 c, f32 x, f32 y) {
    if (D_001E0FE0 == 1) {
        D_001E0FD8 = a;
        D_001E0FE8 = x;
        D_001E0FEC = y;
        D_001E0FE0 = 2;
        D_001E0FF0 = b;
        D_001E0FF4[0] = c;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004BE138 */
