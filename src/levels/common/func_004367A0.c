#include "common.h"

/* localdecomp:start func_004367A0 */
typedef struct E_004367A0 { s16 a; s16 h; u8 pad[12]; } E_004367A0;
void func_004367A0(u8 *a, s32 *o1, s32 *o2) {
    u8 *s = *(u8 **)(a + 0x24);
    u32 c = s[0x2C];
    if (c != 0) {
        s32 h = *(s16 *)(s + (c << 4) + 2);
        s32 z;
        *o1 = h;
        __asm__("plzcw %0,%1" : "=r"(z) : "r"(h << 1));
        *o2 = 30 - z;
    } else {
        *o1 = 0;
        *o2 = 0;
    }
}
/* localdecomp:end func_004367A0 */
