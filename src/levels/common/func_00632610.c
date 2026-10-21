#include "common.h"

/* localdecomp:start func_00632610 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00632610;
extern V_00632610 D_0025F860[];
extern void func_0062F9A8(u8 *, V_00632610 *, s32, f32, f32, f32);
extern s32 func_0057F278(V_00632610 *, V_00632610 *, s32, s32, s32);
extern f32 func_0058F478(V_00632610 *, V_00632610 *);

s32 func_00632610(u8 *o, f32 *out, f32 a, f32 b) {
    V_00632610 p;
    V_00632610 q;
    func_0062F9A8(o, &p, 1, *(f32 *)(o + 0x1F4) - 0.02f, 0.0f, a);
    func_0062F9A8(o, &q, 1, b, 0.0f, a);
    if (func_0057F278(&p, &q, 2, 0, 0) != 0) {
        if (out != 0) {
            *out = func_0058F478(&p, &D_0025F860[0]);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00632610 */
