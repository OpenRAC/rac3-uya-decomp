#include "common.h"

/* localdecomp:start func_0044F1E8 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_00435E70(s32, s32);
extern void func_00439610(u8 *);

u8 *func_0044F1E8(u8 *src, s32 id, s32 type) {
    u8 *m;
    long t;

    m = func_00435E70(id, 128);
    if (m != 0) {
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(f32 *)(m + 44) *= *(f32 *)(src + 44) / *(f32 *)(*(u8 **)(src + 36) + 36);
        *(u128_t *)(m + 16) = *(u128_t *)(src + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(src + 240);
        t = *(long *)(src + 56);
        m[48] = type;
        *(s16 *)(m + 52) = 0;
        *(long *)(m + 56) = t;
        func_00439610(m);
        return m;
    }
    return 0;
}
/* localdecomp:end func_0044F1E8 */
