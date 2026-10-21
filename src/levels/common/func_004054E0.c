#include "common.h"

/* localdecomp:start func_004054E0 */
typedef struct {
    u8 pad0[16];
    f32 *w16;
    u32 w20;
    u8 pad1[4];
    s32 w28;
    s16 h32;
    s16 h34;
    s16 h36;
    s16 h38;
    u8 pad2[8];
} S4054E0;

extern S4054E0 D_001E6FE0[];

void func_004054E0(u32 *buf, s32 idx) {
    S4054E0 *s = &D_001E6FE0[idx];
    s32 n = s->h36 * s->h38;
    s32 count = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        if (s->w20 < (buf[i] & 0xFFFFFF)) {
            count++;
        }
    }
    *(&D_001E6FE0[idx])->w16 = (f32)(n - count) / (f32)n;
}
/* localdecomp:end func_004054E0 */
