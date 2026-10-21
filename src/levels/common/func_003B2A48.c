#include "common.h"

/* localdecomp:start func_003B2A48 */
extern u8 *D_001E009C;
extern void func_003B19C0(u8 *a0, s32 a1);
extern void func_003B3CC0(u8 *a0, s32 a1);

void func_003B2A48(u8 *moby, s32 *link) {
    u8 *p;

    func_003B19C0(moby, 0);
    p = D_001E009C + link[0] * 256;
    while (*(s16 *)(p + 170) != 6628) {
        p = D_001E009C + **(s32 **)(p + 104) * 256;
    }
    func_003B3CC0(p, 0);
}
/* localdecomp:end func_003B2A48 */
