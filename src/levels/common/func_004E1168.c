#include "common.h"

/* localdecomp:start func_004E1168 */
typedef struct {
    u8 pad0[8800];
    f32 x2260;
    f32 x2264;
} S_004E1168;

extern S_004E1168 D_001A4BE0;

extern f32 func_004450C0(f32 *, f32, f32);

void func_004E1168(f32 *out, f32 *st, f32 k) {
    f32 buf[2];

    buf[0] = -D_001A4BE0.x2260;
    buf[1] = -D_001A4BE0.x2264;
    func_004450C0(&st[2], buf[0], k);
    if (st[2] > 1.0f) {
        st[2] = 1.0f;
    }
    if (st[2] < -1.0f) {
        st[2] = -1.0f;
    }
    out[0] = st[2];
    func_004450C0(&st[1], buf[1], k);
    if (st[1] > 1.0f) {
        st[1] = 1.0f;
    }
    if (st[1] < -1.0f) {
        st[1] = -1.0f;
    }
    out[1] = st[1];
}
/* localdecomp:end func_004E1168 */
