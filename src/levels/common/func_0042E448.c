#include "common.h"

extern s32 D_001D545C;
extern s32 D_002F14F0[];
extern s32 D_001EFEA0[];

void func_0042E448(s32 val, s32 idx) {
    s32 m = D_001D545C;
    if (m < 19) {
        idx += *(s32 *)((m << 2) + (s32)D_002F14F0);
        *(s32 *)((idx << 2) + (s32)D_001EFEA0) = val;
    }
}
