#include "common.h"

/* localdecomp:start func_00572798 */
typedef struct {
    u8 pad[0x1C];
    u8 *p;
} E_00572798;
extern s32 D_001D5A18;
extern s32 D_002412A8[];
extern s32 D_00242A94[];
extern E_00572798 *D_0024B950[];
extern f32 D_0024BAD0[];

s32 func_00572798(u8 *a0) {
    u8 *o;
    s32 v;
    f32 f;
    if (*(s32 *)(a0 + 0x94) > 0) {
        return -1;
    }
    o = D_0024B950[0][*(s16 *)(a0 + 0x84)].p;
    if (D_00242A94[0] == 0) {
        if (*(s16 *)(o + 0x44) > 0) {
            f = *(s16 *)(o + 0x44) / 30.0f;
            if (f > 1.0f) {
                f = 1.0f;
            }
            if (f < 0.0f) {
                f = 0.0f;
            }
            D_0024BAD0[0] = f;
            (*(s16 *)(o + 0x44))--;
        } else {
            v = D_001D5A18;
            goto done;
        }
    }
    v = D_002412A8[0];
done:
    if (v == 0) {
        return -1;
    }
    return 1;
}
/* localdecomp:end func_00572798 */
