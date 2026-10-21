#include "common.h"

/* localdecomp:start func_0045CB98 */
extern void func_0045CB98(s32, long);

void func_0045CB98(s32 a, long l) {
    s16 *p = (s16 *)(u32)l; 
    if (p != 0 && a != 0 && p[5] == 2) {
        p[5] = 3;
    }
}
/* localdecomp:end func_0045CB98 */
