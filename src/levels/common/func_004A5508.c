#include "common.h"

typedef int Q_4A5508 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4A5508;
typedef struct {
    V_4A5508 r0;
    V_4A5508 r1;
    V_4A5508 r2;
} M_4A5508;
typedef struct {
    u8 pad0[0x50];
    f32 f50;
} O_4A5508;

extern V_4A5508 D_001E2E40;
extern void func_0040C8E0(M_4A5508 *, V_4A5508 *);
extern void func_0040C2F8(V_4A5508 *, V_4A5508 *, M_4A5508 *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BF68(V_4A5508 *);
extern f32 func_0040CF10(f32, f32);
extern f32 func_0040CEC8(f32, f32);

/* localdecomp:start func_004A5508 */
s32 func_004A5508(O_4A5508 *o, V_4A5508 *p)
{
    M_4A5508 m;
    V_4A5508 r;
    V_4A5508 v;
    V_4A5508 u;
    V_4A5508 w;
    Q_4A5508 x, y;
    f32 ang;
    f32 d;
    f32 zero;
    V_4A5508 *g;

    g = &D_001E2E40;
    func_0040C8E0(&m, g);
    v = *(V_4A5508 *)((u8 *)g - 896);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("vsub.xyz %0, vf0, %1" : "=j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(y));
    v.w = 1.0f;
    func_0040C2F8(&r, &v, &m);
    w = *p;
    w.w = 1.0f;
    func_0040C2F8(&w, &w, &m);
    ang = -func_0040C490(w.x, w.y);
    zero = 0.0f;
    if (ang < zero) {
        ang += 6.2831855f;
    }
    if (func_0040BF68(&u) < 2.0f) {
        if (zero <= o->f50) {
            d = func_0040CF10(ang, o->f50);
            if (d > 0.2f) {
                ang = func_0040CEC8(o->f50, 0.2f);
            } else if (d < -0.2f) {
                ang = func_0040CF10(o->f50, 0.2f);
            }
        }
        o->f50 = ang;
    } else {
        o->f50 = -1.0f;
    }
    return (s32)(ang * 180.0f * 0.31830987f);
}
/* localdecomp:end func_004A5508 */
