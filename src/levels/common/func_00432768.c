#include "common.h"

extern u8 D_002E74B8[];
extern s32 func_00432730();

extern u8 D_002E74B8[];
u16 func_00432768(u8 *p, u32 n) {
    u8 *end;
    s32 r;
    s32 k;
    if ((u32)func_00432730((s32 *)D_002E74B8) < n) return 0;
    end = p + n;
    r = 0xEDB88320;
    for (; p < end; p++) {
        r ^= *p << 8;
        for (k = 7; k >= 0; k--) {
            if (r & 0x8000) r = (r << 1) ^ 0x1F45;
            else r = r << 1;
        }
    }
    return r;
}
