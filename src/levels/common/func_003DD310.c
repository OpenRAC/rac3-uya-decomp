#include "common.h"

extern s32 D_001D6694;
extern u8 *D_001D52FC;
extern u8 D_001A4BE0[];
extern void func_00457288(s32, s32, s32, s32, s32);

void func_003DD310(u8 *m) {
    if (m[0x20] == 0) {
        m[0x20] = 1;
    }
    if (D_001D6694 == 0) {
        u8 *p = D_001A4BE0;
        if ((*(u32 *)(D_001D52FC + 0x1A4) & *(u32 *)(p + 0x1210)) != 0 &&
            *(s32 *)(p + 0x1220) >= 23) {
            func_00457288(5, 1, 4, 0, 0);
        }
    }
}
