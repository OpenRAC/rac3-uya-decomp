#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_0040CD60(u8 *a0);
extern void func_00474548(u8 *a0, s32 a1);

s32 func_00346D58(u8 *moby, u8 *info) {
    s32 flags = *(s32 *)(info + 32);
    *(s32 *)(info + 32) = flags & ~4;
    if ((flags & 2) || (info[32] ^ 1) & 1) {
        func_0040CD60(moby);
        return 1;
    }
    *(u128_t *)(moby + 16) = *(u128_t *)info;
    *(u16 *)(moby + 52) = (*(u16 *)(moby + 52) | 0x41) & 0xEFFF;
    *(s32 *)(moby + 152) = 0;
    func_00474548(moby, 1);
    return 0;
}
