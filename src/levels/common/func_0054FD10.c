#include "common.h"

/* localdecomp:start func_0054FD10 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_54FD10;
typedef int Q_54FD10 __attribute__((mode(TI)));
extern s32 *D_001D5A10;
extern s32 func_005BC958(V_54FD10 *, s32, f32);
extern u8 *func_006197C0(s32);
extern f32 func_0058F4E0(u8 *, V_54FD10 *);

s32 func_0054FD10(u8 *a, V_54FD10 *b) {
    V_54FD10 t;
    f32 r;
    s32 i;

    if (a[0x31] != 0) {
        *(Q_54FD10 *)&t = *(Q_54FD10 *)b;
        b->w = 0.5f;
        r = 36.0f;
        if (func_005BC958(&t, 0, r) == 0) {
            return 0;
        }
        for (i = 0; i < *D_001D5A10; i++) {
            if (func_0058F4E0(func_006197C0(i) + 0xA0, b) < r) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_0054FD10 */
