#include "common.h"

extern u8 D_00142CC1[];
extern u8 D_00142700[];
extern u8 D_001D5576;
extern void func_004B72F8(s32);
/* localdecomp:start func_004B73B8 */
void func_004B73B8(void) {
    func_004B72F8(1);
    if (D_00142CC1[0]) {
        func_004B72F8(2);
    }
    if (D_00142700[0]) {
        func_004B72F8(3);
    }
    if (*(volatile u8 *)&D_001D5576) {
        func_004B72F8(4);
    }
}
/* localdecomp:end func_004B73B8 */
