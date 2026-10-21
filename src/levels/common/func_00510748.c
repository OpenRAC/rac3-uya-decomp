#include "common.h"

/* localdecomp:start func_00510748 */
extern s32 D_001D4C40[];

void func_00510748(s32 *dst) {
    s32 *src = D_001D4C40;
    s32 i;
    for (i = 3; i >= 0; i--) {
        *dst++ = *src++;
    }
}
/* localdecomp:end func_00510748 */
