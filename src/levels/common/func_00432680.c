#include "common.h"

/* localdecomp:start func_00432680 */
extern u8 D_002E74B8[];
extern u8 D_002E7748[];
extern s32 func_00432730();
extern s32 func_00432850();
void func_00432680(u8 *p) {
    s32 i;
    *(s32 *)p = func_00432730(D_002E74B8);
    *(s32 *)(p + 4) = func_00432730(D_002E7748);
    p += 8;
    p += func_00432850(p, 0, D_002E74B8);
    for (i = 0; i < 0x25; i++) {
        p += func_00432850(p, i, D_002E7748);
    }
}
/* localdecomp:end func_00432680 */
