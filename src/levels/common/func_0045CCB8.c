#include "common.h"

/* localdecomp:start func_0045CCB8 */
extern s16 D_001CCFFC[];
void func_0045CCB8(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (*(s16 *)(p + 0xA) == 1) {
                *(s16 *)(p + 0xA) = 4;
                if (*(s16 *)(p + 0x10) != 0) {
                    D_001CCFFC[0] = 1;
                }
            }
        } else {
            *(s16 *)(p + 0xA) = 0;
        }
    }
}
/* localdecomp:end func_0045CCB8 */
