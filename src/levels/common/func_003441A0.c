#include "common.h"

/* localdecomp:start func_003441A0 */
extern s32 D_00279840[];
void func_003441A0(void) {
    s32 i;
    for (i = 299; i >= 0; i--) {
        D_00279840[i * 20 + 18] = 0;
    }
}
/* localdecomp:end func_003441A0 */
