#include "common.h"

extern void func_004AD4B8(void);

extern s32 D_001D4B00;
extern s32 D_001D4B34;
extern s32 D_001D4B30;
extern s32 D_0023B360[];
void func_004AD4B8(void) {
    s32 i;
    s32 *p = D_0023B360;
    D_001D4B34 = 0;
    D_001D4B30 = D_001D4B00;
    for (i = 0x3F; i >= 0; i--) {
        p[0] = 0;
        p[1] = 0;
        p += 4;
    }
}
