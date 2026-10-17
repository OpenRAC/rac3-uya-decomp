#include "common.h"

extern u8 *D_002485DC[];
extern s32 func_003F5B50(u8 *);

s32 func_00413A30(u8 *a0) {
    s32 idx = *(s32 *)(*(u8 **)(a0 + 104) + 80);
    s32 r = 0;
    if (idx >= 0) {
        r = func_003F5B50(D_002485DC[0] + (idx << 8));
    }
    return r;
}
