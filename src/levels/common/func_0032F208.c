#include "common.h"

/* localdecomp:start func_0032F208 */
extern f32 func_00442070(f32);
extern void func_00449008(void *, void *, void *, s32, f32);
extern void func_0032F2F0(u8 *, void *);

void func_0032F208(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    func_00449008(v + 48, v + 16, v + 32, 0, func_00442070(*(f32 *)(v + 84)));
    *(f32 *)(v + 84) += *(f32 *)(v + 88);
    func_0032F2F0(a0, v + 48);
    if (*(f32 *)(v + 84) > 0.9f) {
        *(s32 *)(v + 80) = 1;
    } else {
        *(s32 *)(v + 80) = 0;
    }
    if (*(f32 *)(v + 84) >= 1.0f) {
        *(f32 *)(v + 84) = 1.0f;
        *(s16 *)(v + 76) = 1;
    }
}
/* localdecomp:end func_0032F208 */
