#include "common.h"

/* localdecomp:start func_0048DBE0 */
extern u8 D_00143950[];
extern void func_004A7368(s32, s32, s32);
extern void func_003FFAC8(void);
void func_0048DBE0(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_004A7368(3, 0, 0);
        p = D_00143950;
        p[173] = p[173] == 0;
        func_003FFAC8();
    }
}
/* localdecomp:end func_0048DBE0 */
