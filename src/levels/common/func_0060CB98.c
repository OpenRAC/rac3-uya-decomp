#include "common.h"
extern s32 func_0060DF40();
extern s32 func_0060C9A0();
extern s32 func_0060D2A8(s32);
extern s32 func_0060DC48();
s32 func_0060CB98(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_0060DF40(*q);
        *q = 0;
        for (i = 15; i >= 0; i--) {
            func_0060DC48(func_0060D2A8(func_0060C9A0(p)));
        }
        return 1;
    }
    return 0;
}
