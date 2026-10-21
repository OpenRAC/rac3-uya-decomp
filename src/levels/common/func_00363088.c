#include "common.h"

/* localdecomp:start func_00363088 */
extern s32 D_001DD7D0;
extern s32 D_0028F140[];

s32 func_00363088(s32 value) {
    s32 i;
    for (i = 0; i < D_001DD7D0; i++) {
        if (D_0028F140[i] == value) return 1;
    }
    return 0;
}
/* localdecomp:end func_00363088 */
