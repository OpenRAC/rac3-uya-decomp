#include "common.h"

/* localdecomp:start func_003B4CC0 */
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;

typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;

s32 func_003B4CC0(S_3B4CC0 *a0) {
    s32 r = a0->p68->w10 * 0;
    S_3B4CC0b *p = a0->p68;
    r = p->w10;
    if (p->w30 > 0) {
        r += p->w30;
    } else if (p->w30 < 0) {
        r += p->w1C * 2;
    }
    return r;
}
/* localdecomp:end func_003B4CC0 */
