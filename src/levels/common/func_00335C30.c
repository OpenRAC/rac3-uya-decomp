#include "common.h"

/* localdecomp:start func_00335C30 */
extern s32 D_001DCF48;
extern s32 D_001DCF58;

void *func_00335C30(void *self, s32 index, s32 *count) {
    switch (index) {
    case 0:
        *count = 16;
        return &D_001DCF48;
    case 1:
        *count = 28;
        return &D_001DCF58;
    }
    return 0;
}
/* localdecomp:end func_00335C30 */
