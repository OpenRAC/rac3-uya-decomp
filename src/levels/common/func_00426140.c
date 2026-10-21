#include "common.h"

/* localdecomp:start func_00426140 */
typedef int Q_426140 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_426140;

extern u8 *func_003CE770(s32 a, s32 b, s32 c, s32 d, V4_426140 *pos, V4_426140 *rot, V4_426140 *vel, s32 e,
                         f32 f, f32 g, s32 h, s32 i, s32 j);
extern void func_002FD820();
extern void func_00410370(u8 *m, s32 r, s32 g, s32 b);
extern s32 func_004182B0(s32 n);
extern f32 func_00418328(f32 lo, f32 hi);
extern f32 func_004183E0(void);
extern void func_004184F0(V4_426140 *out, f32 lo, f32 hi);

void func_00426140(s32 cls, V4_426140 *org, s32 n, s32 flag, V4_426140 *base, s32 color, V4_426140 *rotp, s32 arg,
                   f32 spread, f32 speed, f32 slo, f32 shi) {
    V4_426140 vel;
    V4_426140 pos;
    V4_426140 rot;
    V4_426140 r;
    Q_426140 a, b;
    u8 *m;
    s32 k;
    s32 i;
    s32 cr, cg, cb, ca;
    u8 *mv;

    for (i = 0; i < n; i++) {
        func_004184F0(&vel, 0.0f, speed * 0.016666668f);
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(vel));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*base));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(vel) : "j"(b));
        func_004184F0(&pos, 0.0f, spread);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*org));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(a));
        *(Q_426140 *)&r = 0;
        r.x = func_004183E0();
        r.z = func_004183E0();
        rot = r;
        if (rotp != 0) {
            rot = *rotp;
        }
        k = func_004182B0(4);
        m = func_003CE770(cls, flag != 0 ? 2 : 1, 0x1C32, k, &pos, &rot, &vel, 0xFF,
                          func_00418328(10.0f, 20.0f), func_00418328(10.0f, 20.0f), arg, 0, 0x80);
        if (m != 0) {
            *(void (**)())(m + 0x64) = func_002FD820;
            cr = color & 0xFF;
            ca = (u32)color >> 24;
            *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * func_00418328(slo, shi);
            cb = (color >> 16) & 0xFF;
            cg = (color >> 8) & 0xFF;
            mv = *(u8 **)(m + 0x68);
            func_00410370(m, cr, cg, cb);
            m[0x23] = ca;
            if (cr != cg || cr != cb) {
                ca = 1;
            } else {
                ca = 0;
            }
            *(s32 *)(mv + 0x50) = (ca << 24) | (cb << 16) | (cg << 8) | cr;
        }
    }
}
/* localdecomp:end func_00426140 */
