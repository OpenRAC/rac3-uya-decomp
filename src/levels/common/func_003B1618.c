#include "common.h"

/* localdecomp:start func_003B1618 */
extern s32 D_001D545C;
extern u32 D_001D4C38;
extern u32 D_001A7DD0[];
extern u8 D_00142738[];
extern u8 D_001439F4[];
extern u32 D_001A8414[];
extern u32 D_001A842C[];
extern s32 D_001C5290[][16];
extern s32 func_0050FF18(void);
extern s32 func_00326EE8(void);
extern void func_00417F60(s32, s32);

void func_003B1618(s32 unused, s32 *msg) {
    if (D_001D545C == 4) {
        if (*msg == 100 && D_00142738[0] == 0 && D_001439F4[0] == 0
            && D_001D4C38 - D_001A7DD0[0] > 0x34BC0 && func_0050FF18() == 0
            && !(D_001A8414[0] & (1 << D_001D545C))) {
            func_00417F60(3286, 127);
        }
    } else if (D_001D545C == 12) {
        s32 v = func_00326EE8();
        if (D_001C5290[D_001D545C][v] == 3 && D_001439F4[0] == 0
            && D_001D4C38 - D_001A7DD0[0] > 0x11940 && func_0050FF18() == 0
            && !(D_001A842C[0] & (1 << D_001D545C))) {
            func_00417F60(3288, 129);
        }
    }
}
/* localdecomp:end func_003B1618 */
