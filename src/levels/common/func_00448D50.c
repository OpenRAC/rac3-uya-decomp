#include "common.h"

/* localdecomp:start func_00448D50 */
typedef int Q_448D50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_448D50;
typedef struct {
    u8 pad0[0x30];
    V4_448D50 v30;
    u8 v40[0x40];
} E_448D50;
extern E_448D50 *D_001E01AC;
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BF68(void *);
s32 func_00448D50(V4_448D50 *p, s32 i) {
    V4_448D50 d, r;
    Q_448D50 x, y;
    E_448D50 *e;
    if (i < 0) {
        return 0;
    }
    e = (E_448D50 *)((u8 *)D_001E01AC + i * 128);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->v30));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    d.w = 0.0f;
    func_0040C2D0(&r, &d, e->v40);
    if (func_0040BF68(&r) < 1.0f && r.z >= -1.0f && r.z <= 1.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00448D50 */
