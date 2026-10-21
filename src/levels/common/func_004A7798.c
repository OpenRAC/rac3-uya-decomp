#include "common.h"

/* localdecomp:start func_004A7798 */
typedef struct {
    u8 p0[0x40];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    u8 p44[0xB0 - 0x44];
    s32 wB0;
    s32 wB4;
} S_004A7798;

extern S_004A7798 D_001A30B0[];

void func_004A7798(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    S_004A7798 *s = D_001A30B0;
    s->wB0 = a0;
    if (s->b40 != a1) {
        s->b40 = a1;
        s->b43 |= 1;
    }
    if (s->wB4 != a2) {
        s->wB4 = a2;
        s->b43 |= 4;
    }
    if (s->b41 != a3 || s->b42 != a4) {
        s->b42 = a4;
        s->b41 = a3;
        s->b43 |= 2;
    }
}
/* localdecomp:end func_004A7798 */
