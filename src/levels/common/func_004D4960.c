#include "common.h"

/* localdecomp:start func_004D4960 */
extern s32 D_001D9870;

extern u32 D_00142BA0[];
extern s32 D_001D9870;
extern s32 func_004D2128();
extern s32 func_004D2120();
s32 func_004D4960(s32 a, s32 b, u32 c) {
    u32 w;
    if (a == -1 || func_004D2128() == a) {
        if (b == -1 || func_004D2120() == b) {
            w = c >> 2;
            if (!(D_00142BA0[w] & (1 << (c & 0x1F)))) {
                D_001D9870 = c;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_004D4960 */
