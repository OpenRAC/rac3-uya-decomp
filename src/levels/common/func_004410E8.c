#include "common.h"

/* localdecomp:start func_004410E8 */
extern u8 D_00142660[];
extern s32 func_00417EA0(void);
extern void func_00475A50(s32 a0);
void func_004410E8(void) {
    if (func_00417EA0() != 0) {
        if (D_00142660[90] + 1 < 20) {
            D_00142660[91]++;
            if (D_00142660[91] * 2 >= D_00142660[90] + 1) {
                func_00475A50(180);
                D_00142660[91] = 0;
                D_00142660[90]++;
            }
        }
    }
}
/* localdecomp:end func_004410E8 */
