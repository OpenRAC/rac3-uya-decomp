#include "common.h"

/* localdecomp:start func_004C4A18 */
typedef int u128_4C4A18 __attribute__((mode(TI)));

typedef struct {
    u128_4C4A18 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 *x1C;
} E_4C4A18;

typedef struct {
    u8 pad0[872];
    s16 x368;
    u8 pad36A[8790];
    u8 *x25C0;
} S_4C4A18;

extern void func_0044DF40(u128_4C4A18 *, E_4C4A18 *, s32);
extern E_4C4A18 D_00250180[];
extern S_4C4A18 D_001A4BE0;

s32 func_004C4A18(u8 *a0, u128_4C4A18 *a1, f32 f12, f32 f13, f32 f14) {
    u128_4C4A18 v;
    E_4C4A18 *e = D_00250180;
    s32 i;
    for (i = 0; i < 128; i++, e++) {
        if (e->x1C == 0) {
            if (a1 != 0) {
                v = *a1;
            } else {
                v = *(u128_4C4A18 *)(a0 + 16);
            }
            e->x1C = a0;
            e->x10 = f12;
            e->x14 = f13;
            e->x18 = f14;
            if (D_001A4BE0.x368 != 0) {
                e->pos = *(u128_4C4A18 *)(D_001A4BE0.x25C0 + 224);
            } else {
                func_0044DF40(&v, e, 1);
            }
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_004C4A18 */
