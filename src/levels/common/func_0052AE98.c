#include "common.h"

/* localdecomp:start func_0052AE98 */
typedef int Q_52AE98 __attribute__((mode(TI)));
extern u8 *func_005A8280(s32, s32);
extern void func_005AA648(u8 *, s32, s32, s32);
extern void func_005A98E8(u8 *, s32, u8 *);
extern void func_005B2BD0(u8 *, s32, s32, s32);
extern void func_005AB3B0(u8 *);

u8 *func_0052AE98(u8 *src, f32 v) {
    u8 *m = func_005A8280(0x18E1, 0x80);

    if (m != 0) {
        u8 *d = *(u8 **)(m + 0x68);
        *(f32 *)(d + 4) = v;
        *(u8 **)(d + 0) = src;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        func_005AA648(m, 0x80, 0x80, 0x80);
        func_005A98E8(src, 0, m + 0x10);
        *(Q_52AE98 *)(m + 0xC0) = *(Q_52AE98 *)(src + 0xC0);
        *(Q_52AE98 *)(m + 0xD0) = *(Q_52AE98 *)(src + 0xD0);
        *(Q_52AE98 *)(m + 0xE0) = *(Q_52AE98 *)(src + 0xE0);
        if (m[0x43] != 0) {
            func_005B2BD0(m, 0, 0, 10);
        }
        func_005AB3B0(m);
        m[0x20] = 0;
        *(u16 *)(m + 0x34) |= 5;
    }
    return m;
}
/* localdecomp:end func_0052AE98 */
