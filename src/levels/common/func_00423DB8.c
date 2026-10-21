#include "common.h"

/* localdecomp:start func_00423DB8 */
void func_00423DB8(u8 *a0, s32 i) {
    u8 *p = *(u8 **)(a0 + (i << 2) + 72);
    s32 *q;
    s32 j;
    if (*(s32 *)(p + 20) != 0) {
        *(s32 *)(p + 20) = (s32)p + *(s32 *)(p + 20);
    }
    j = 0; if (p[16] != 0) { q = (s32 *)(p + 28); do { *q = (s32)p + *q; j++; q++; } while (j < p[16]); }
}
/* localdecomp:end func_00423DB8 */
