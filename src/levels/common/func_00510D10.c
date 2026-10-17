#include "common.h"

extern s32 func_005121D8();

extern s32 func_005121D8();
extern s32 func_00510B30();
extern s32 func_00511508(s32);
extern s32 func_00511EE0();
s32 func_00510D10(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_005121D8(*q);
        *q = 0;
        for (i = 3; i >= 0; i--) {
            func_00511EE0(func_00511508(func_00510B30(p)));
        }
        return 1;
    }
    return 0;
}
