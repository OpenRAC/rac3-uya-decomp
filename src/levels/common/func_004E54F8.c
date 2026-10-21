#include "common.h"

/* localdecomp:start func_004E54F8 */
extern s32 func_004E5470(void);

s32 func_004E54F8(void) {
    s32 v = func_004E5470();

    if (v == 13 || v == 28 || v == 29 || v == 14) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004E54F8 */
