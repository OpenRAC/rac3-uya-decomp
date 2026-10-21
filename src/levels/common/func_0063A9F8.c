#include "common.h"

/* localdecomp:start func_0063A9F8 */
extern void func_00674710(u8);

void func_0063A9F8(u8 *self, s32 force) {
    if ((self[0x1A14] != 0 || force != 0) && *(s32 *)(self + 0x251C) != 0) {
        *(s32 *)(self + 0x251C) = 0;
        self[0x24AA] = 1;
        func_00674710(self[0x24C9]);
        if (*(s16 *)(self + 0x24A8) == 0) {
            *(s16 *)(self + 0x24A8) = 0x14;
        }
    }
}
/* localdecomp:end func_0063A9F8 */
