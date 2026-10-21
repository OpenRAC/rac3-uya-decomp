#include "common.h"

/* localdecomp:start func_00440760 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001E0180;
extern void func_0040C2D0_0037E0F0(void *, void *, void *);
s32 func_00440760(void *a, s32 idx, Q_37E0F0 *out) {
    V4_37E0F0 v;
    V4_37E0F0 r;
    u8 *e;
    Q_37E0F0 p, q, t;
    if (idx == -1) {
        return 0;
    }
    e = D_001E0180 + idx * 0x80;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_37E0F0 *)a));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_37E0F0 *)(e + 0x30)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(t));
    v.w = 0.0f;
    func_0040C2D0_0037E0F0(&r, &v, e + 0x40);
    if (out != 0) {
        *out = *(Q_37E0F0 *)&r;
    }
    if (r.x >= -1.0f && r.x <= 1.0f && r.y >= -1.0f && r.y <= 1.0f && r.z >= -1.0f && r.z <= 1.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00440760 */
