#include "common.h"
extern u8 *func_003252E8(void);
extern s32 func_00328AA8(u8 *);
s32 func_00327970(void) {
    s32 n = 0;
    u8 *l = *(u8 **)(func_003252E8() + 104);
    u8 *o = *(u8 **)(l + 4);
    while (o) {
        u8 *b = *(u8 **)(o + 104);
        if (!func_00328AA8(o)) {
            o = *(u8 **)(b + 108);
        } else {
            if (o == *(u8 **)(l + 8)) {
                return n;
            }
            o = *(u8 **)(b + 108);
            n++;
        }
    }
    return 0;
}
