#include "common.h"

/* localdecomp:start func_00312998 */
extern u8 *D_001E17B0;
extern s32 func_0040BA90(void *);
extern s32 func_0013D3E0(void);
extern void func_00312AE8(void *, s32, f32, f32, s32);
extern void func_00312F80(void *);

void func_00312998(s32 a0) {
    s32 i;
    for (i = 0; i < 1; i++) {
        u8 *e = (u8 *)(i * 80 + (s32)D_001E17B0);
        if (*(s32 *)(e + 48) == a0) {
            if (func_0040BA90(e + 52) != 0) {
                if (*(s32 *)(e + 56) == 0) {
                    *(s32 *)(e + 48) = 0;
                }
            } else if (!(func_0013D3E0() & 1)) {
                func_00312AE8(e, 0, 0.0f, 0.0f, 0);
                func_00312AE8(e, 0, 0.0f, 0.0f, 0);
            }
            func_00312F80(e);
        }
    }
}
/* localdecomp:end func_00312998 */
