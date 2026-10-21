#include "common.h"

/* localdecomp:start func_00458E48 */
extern u8 *func_00458650(void *);

s32 func_00458E48(void *a0, u16 *a1, s32 a2, s32 a3) {
    u8 *p;

    p = func_00458650(a0);
    if (p == 0) {
        return 0;
    }
    *(u16 **)(p + 196) = a1;
    *(s32 *)(p + 156) &= ~4;
    if (a2 == -1) {
        *(s16 *)(p + 202) = *a1 - 1;
    } else {
        *(s16 *)(p + 202) = a2;
    }
    *(s16 *)(p + 200) = a3;
    return 1;
}
/* localdecomp:end func_00458E48 */
