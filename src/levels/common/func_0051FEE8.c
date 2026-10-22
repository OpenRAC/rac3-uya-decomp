#include "common.h"

/* localdecomp:start func_0051FEE8 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_005BC768(s32, s32);
extern void func_005A8630(u8 *);
extern s32 func_005904B8(u128_t *, f32);
extern void func_0051FF78(u8 *);
extern void func_005201C8(u8 *);

void func_0051FEE8(u8 *o) {
    u8 *t = *(u8 **)(o + 0x68);
    u128_t v;
    if (t == 0) {
        return;
    }
    if (func_005BC768(*(s16 *)(o + 0xAA), *(s32 *)(t + 0x28)) == 0) {
        func_005A8630(o);
        return;
    }
    v = *(u128_t *)(o + 0x10);
    ((f32 *)&v)[3] = 2.0f;
    if (func_005904B8(&v, 100.0f) != -1) {
        func_0051FF78(o);
        func_005201C8(o);
    }
}
/* localdecomp:end func_0051FEE8 */
