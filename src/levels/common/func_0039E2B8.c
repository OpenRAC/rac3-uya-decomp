#include "common.h"

/* localdecomp:start func_0039E2B8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_003E4858(void *, void *, f32);
extern u8 *D_001DEA1C;
void func_0039E2B8(u8 *src, s32 idx, f32 a, f32 b, f32 c, f32 d, f32 e, f32 g, f32 t) {
    u8 *p = D_001DEA1C + (idx << 8);
    f32 x = a + (b - a) * t;
    f32 y;
    func_003E4858(p + 0xC0, p + 0xC0, x);
    func_003E4858(p + 0xD0, p + 0xD0, x);
    y = c + (d - c) * t;
    func_003E4858(p + 0xE0, p + 0xE0, y);
    *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
    *(f32 *)(p + 0x18) += (e + (g - e) * t) - y * 0.55f;
}
/* localdecomp:end func_0039E2B8 */
