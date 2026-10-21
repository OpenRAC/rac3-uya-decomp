#include "common.h"

/* localdecomp:start func_00419718 */
extern u8 D_001DFD72;
extern u8 D_001DFD73;
extern s16 D_001DFD48[4];
extern s16 D_001DFD60[4];

void func_00419718(s32 a, s32 b) {
    s32 i;
    if (D_001DFD72 < 9) {
        for (i = D_001DFD72 - 1; i >= 0; i--) {
            if (D_001DFD48[(D_001DFD73 + i) % 9] == a) {
                return;
            }
        }
        D_001DFD48[(D_001DFD73 + D_001DFD72) % 9] = a;
        D_001DFD60[(D_001DFD73 + D_001DFD72) % 9] = b;
        D_001DFD72++;
    }
}
/* localdecomp:end func_00419718 */
