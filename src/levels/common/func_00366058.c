#include "common.h"

/* localdecomp:start func_00366058 */
extern s32 D_001A71A4[];
extern s32 D_001E1CE0;
extern f32 D_001E1CE4;
void func_00366058(void) {
    if (D_001A71A4[0] == 1) {
        D_001E1CE0++;
        if (D_001E1CE0 > 40) {
            D_001E1CE0 = 40;
        }
    } else {
        D_001E1CE0--;
        if (D_001E1CE0 < 0) {
            D_001E1CE0 = 0;
        }
    }
    D_001E1CE4 = (f32)D_001E1CE0 / 40.0f;
}
/* localdecomp:end func_00366058 */
