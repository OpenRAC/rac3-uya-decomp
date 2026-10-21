#include "common.h"

/* localdecomp:start func_0040D5E0 */
typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_003899B8;
s32 func_0040D5E0(f32 *w, f32 *h, s32 mode) {
    s32 r;
    *w = 0.0f;
    *h = 0.0f;
    r = 0;
    if (D_001D55C4_003899B8 != 0) {
        if (mode != 0) {
            *w = (f32)((D_001D55C4_003899B8[0x41].w4 >> 17) & 0x3F);
            *h = (f32)((D_001D55C4_003899B8[0x41].w4 >> 9) & 0xFF) * 0.25f;
            r = 1;
        } else {
            s32 n = func_0040D5C0();
            if (n > 0) {
                s32 i;
                u32 mx = 0;
                for (i = 0; i < n; i++) {
                    u32 a = (D_001D55C4_003899B8[i].w4 >> 17) & 0x3F;
                    if (mx < a) {
                        mx = a;
                        *h = (f32)((D_001D55C4_003899B8[i].w4 >> 9) & 0xFF) * 0.25f;
                    }
                }
                *w = (f32)mx;
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_0040D5E0 */
