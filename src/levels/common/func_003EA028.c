#include "common.h"

/* localdecomp:start func_003EA028 */
extern s32 D_001A4E18[];
extern void func_003E9BB8(u8 *a0);
extern void func_003F3EA0(void *a0, u8 *a1, f32 f12);
void func_003EA028(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 112) + 224;
    D_001A4E18[0] = 2;
    func_003E9BB8(a0);
    if (*(s32 *)(s0 + 64) != 0) {
        a0[137] = 0;
        func_003F3EA0(*(void **)(a0 + 148), a0 + 48, 0.5f);
    }
}
/* localdecomp:end func_003EA028 */
