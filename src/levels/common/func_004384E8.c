#include "common.h"

/* localdecomp:start func_004384E8 */
extern s32 D_001E00DC;
extern s32 D_001E00D8;
extern s32 D_0021DEA0[];
extern s32 D_001E0148;
void func_004384E8(void) {
    s32 i;
    for (i = D_001E00DC; i < D_001E00D8; i++) {
        D_0021DEA0[i] = 0;
    }
    D_001E0148 = 0;
}
/* localdecomp:end func_004384E8 */
