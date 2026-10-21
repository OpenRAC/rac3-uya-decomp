#include "common.h"

/* localdecomp:start func_00448C50 */
extern u8 *D_001E009C;

void func_00448C50(u8 *moby, s16 *list) {
    s32 i;
    for (i = 1; i <= list[0]; i++) {
        if (D_001E009C + list[i] * 256 == moby) {
            list[i] = list[list[0]];
            list[0]--;
            return;
        }
    }
}
/* localdecomp:end func_00448C50 */
