#include "common.h"

/* localdecomp:start func_003277D0 */
extern u8 *func_003252E8(void);
extern s32 func_00328AA8(u8 *);

s32 func_003277D0(void) {
    s32 n = 0;
    u8 *o = *(u8 **)(*(u8 **)(func_003252E8() + 104) + 4);

    while (o) {
        u8 *b = *(u8 **)(o + 104);
        if (func_00328AA8(o)) n++;
        o = *(u8 **)(b + 108);
    }
    return n;
}
/* localdecomp:end func_003277D0 */
