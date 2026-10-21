#include "common.h"

typedef struct { u8 pad[8]; f32 f8; } O_50D770;
extern u8 D_001A71D4[];
extern f32 func_0050D4D8(O_50D770 *);

/* localdecomp:start func_0050D770 */
f32 func_0050D770(O_50D770 *a, O_50D770 *b, s32 *c, f32 d) {
    s32 n;
    s32 m;
    f32 z;
    f32 r;
    switch (D_001A71D4[0]) {
    case 0:
        z = b->f8;
        n = (s32)(z / d);
        r = (a->f8 + z * (f32)n) - (f32)((n * n + n) >> 1) * d;
        if (c) {
            *c = n;
        }
        return r;
    case 1:
    case 2:
        m = (s32)(func_0050D4D8(b) / d);
        if (c) {
            *c = m;
        }
        return a->f8 + b->f8 * 0.5f;
    default:
        return 0.0f;
    }
}
/* localdecomp:end func_0050D770 */
