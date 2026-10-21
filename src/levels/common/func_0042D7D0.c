#include "common.h"

/* localdecomp:start func_0042D7D0 */
typedef struct {
    u8 pad[12];
    u8 *bits;
} S_0042D7D0;
extern S_0042D7D0 D_001F4020;
extern s32 func_0042DA20(s32);
void func_0042D7D0(s32 x0, s32 y0, s32 w, s32 h) {
    s32 x, y;
    u8 *p;
    s32 m;
    s32 row;
    for (y = y0; y < y0 + h; y++) {
        row = (y >> 5) << 4;
        for (x = x0; x < x0 + w; x++) {
            p = D_001F4020.bits + (y << 6) + x / 8;
            m = 1 << (x & 7);
            func_0042DA20((x >> 5) + row);
            *p |= m;
        }
    }
}
/* localdecomp:end func_0042D7D0 */
