#include "common.h"

/* localdecomp:start func_00417CF0 */
extern u8 D_001426E0[];
extern u8 D_001D5587;
extern void func_004344A0(void);
void func_00417CF0(s32 *p) {
    if (D_001426E0[0x82] & 1) {
        if (D_001426E0[0x14] != 0) {
            if (*p != 3) {
                D_001426E0[0x82] &= 0xFE;
                func_004344A0();
            }
        }
    }
    if (*p == 0xD && D_001D5587 == 0) {
        *p = 0x17;
    } else if (*p == 3) {
        if (D_001426E0[0x82] & 1) {
            *p = 6;
        }
    }
}
/* localdecomp:end func_00417CF0 */
