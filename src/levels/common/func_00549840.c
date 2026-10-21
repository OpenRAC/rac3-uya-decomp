#include "common.h"

/* localdecomp:start func_00549840 */
typedef int Q_549840 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_549840;
extern void func_0058F358(void *, void *, f32);
extern s32 func_0061B008(s32);
extern s32 func_0054A100(void);
static __inline__ void copy3_549840(f32 *d, f32 *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

void func_00549840(u8 *o, u8 *msg) {
    u8 *d;
    V4_549840 t;
    V4_549840 w;
    V4_549840 u;

    if (msg[3] != 8) {
        return;
    }
    d = *(u8 **)(o + 0x68);
    func_0058F358(&t, o + 0xD0, -1.0f);
    copy3_549840((f32 *)(msg + 0x18), &t.x);
    if (*(s32 *)(d + 0x20) != 0) {
        s32 n;
        *(s32 *)(msg + 8) = func_0061B008(*(s32 *)(d + 0x20));
        n = func_0054A100();
        *(Q_549840 *)&u = 0;
        u.x = *(f32 *)(d + 0x44);
        u.y = n;
        u.z = *(f32 *)(d + 0x28);
        w = u;
        copy3_549840((f32 *)(msg + 0xC), &w.x);
    } else {
        *(u32 *)(msg + 8) = 0xFFFFFFFF;
    }
}
/* localdecomp:end func_00549840 */
