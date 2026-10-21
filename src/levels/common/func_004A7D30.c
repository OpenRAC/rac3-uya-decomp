#include "common.h"

/* localdecomp:start func_004A7D30 */
extern s32 D_0023ACF0[];
extern void func_00436220(s32 p);
void func_004A7D30(void) {
    s32 *p = D_0023ACF0;
    s32 i;
    for (i = 19; i >= 0; i--) {
        if (*p) func_00436220(*p);
        *p = 0;
        p++;
    }
}
/* localdecomp:end func_004A7D30 */
