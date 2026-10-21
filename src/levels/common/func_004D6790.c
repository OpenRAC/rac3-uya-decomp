#include "common.h"

/* localdecomp:start func_004D6790 */
extern void func_0045E580(s32);

extern s32 D_001E13CC[];
extern void func_0045E580(s32);
void func_004D6790(void) {
    s32 *p = D_001E13CC;
    s32 i;
    for (i = 5; i >= 0; i--, p++) {
        if (*p) { func_0045E580(*p); *p = 0; }
    }
}
/* localdecomp:end func_004D6790 */
