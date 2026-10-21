#include "common.h"

/* localdecomp:start func_00646268 */
extern u8 D_00483AC0[];
s32 func_00646268(u8 *o, s32 bit) {
    u8 *k = o + 0x1A41;
    u32 buf[2];
    u16 r;
    if (*k == 0) {
        r = 0;
    } else {
        u8 n = *k;
        u8 *d = (u8 *)buf;
        s32 np = n + 1;
        s32 m = ((s32)k - n) & 7;
        s32 i;
        for (i = 0; i < 0x18; i += 3) {
            *d++ = *(D_00483AC0 + (((m + i) & 7) * 0xD1 + np));
        }
        buf[0] ^= (u32)k;
        {
            u32 t = buf[1] ^ buf[0];
            u32 hi = t >> 16;
            buf[1] = hi / (((t ^ hi) << 16) + 1);
        }
        r = *(u16 *)&buf[1];
    }
    return ((s16)r >> bit) & 1;
}
/* localdecomp:end func_00646268 */
