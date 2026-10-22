#include "common.h"

/* localdecomp:start func_00619AE0 */
extern s32 D_00264E68[];
void func_00619AE0(s32 v) {
    s32 i = 0;
    if (D_00264E68[i] == v) {
        D_00264E68[i] = 0;
        return;
    }
loop:
    i++;
    if (i < 0x100) {
        if (D_00264E68[i] != v) {
            goto loop;
        }
        D_00264E68[i] = 0;
    }
}
/* localdecomp:end func_00619AE0 */
