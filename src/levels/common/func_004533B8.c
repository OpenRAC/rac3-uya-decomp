#include "common.h"

/* localdecomp:start func_004533B8 */
extern u8 *D_001DFCC8[];
void func_004533B8(void *a0, s32 a1, s32 a2) {
    if (a0 != 0) {
        u8 *b = D_001DFCC8[0] + a1 * 224;
        u8 *e;
        b[4]++;
        e = b + (b[4] * 8 - 8);
        *(void **)e = a0;
        e[5] = a2;
        *(s16 *)(e + 6) = 0;
    }
}
/* localdecomp:end func_004533B8 */
