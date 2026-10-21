#include "common.h"

/* localdecomp:start func_004A9DE8 */
typedef int Q_4A9DE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4A9DE8;
typedef struct {
    u8 pad0[0x10];
    V4_4A9DE8 v10;
} O_4A9DE8;
extern V4_4A9DE8 D_002EDF00[];
extern f32 func_004408C0(f32, f32);
extern void func_0040C2D0(void *, void *, void *);
extern s32 func_00440848(s32);
extern s32 func_0045FEC8(void *, void *, void *, u32, u32, s32, s32, s32, s32);

void func_004A9DE8(O_4A9DE8 *o, f32 f) {
    V4_4A9DE8 u, v, w;
    Q_4A9DE8 a, b, c;
    V4_4A9DE8 *pu = &u;
    V4_4A9DE8 *pv = &v;
    V4_4A9DE8 *pw = &w;
    s32 i;
    s32 r;
    for (i = 0; i < 6; i++) {
        u.x = func_004408C0(-0.016666668f, 0.016666668f);
        u.y = func_004408C0(-0.016666668f, 0.016666668f);
        u.z = f + func_004408C0(-0.0041666669f, 0.0041666669f);
        u.w = 0.4f;
        w = *(V4_4A9DE8 *)((u8 *)D_002EDF00 + (i << 4));
        v = u;
        v.w = 0.6f;
        func_0040C2D0(pw, pw, (u8 *)o + 0xC0);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(w));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->v10));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(w) : "j"(c));
        r = func_00440848(4);
        func_0045FEC8(pw, pu, pv, 0x30F0F0F0, 0x14F0F0F0, 4, 4, r + 4, 0x17);
    }

}
/* localdecomp:end func_004A9DE8 */
