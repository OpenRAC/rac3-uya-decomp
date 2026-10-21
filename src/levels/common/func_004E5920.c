#include "common.h"

/* localdecomp:start func_004E5920 */
typedef int Q_4E5920 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4E5920;

typedef struct {
    u8 pad0[0x2F0];
    V4_4E5920 v2F0;
    u8 pad300[0x38];
    f32 f338;
    u8 pad33C[0x25C4 - 0x33C];
    s32 w25C4;
} S_4E5920;

typedef struct {
    u8 pad0[0x2584];
    s32 w2584;
} S_4E5920_B;

typedef struct {
    u8 pad0[0x10];
    V4_4E5920 pos;
} O_4E5920;

extern V4_4E5920 D_001A4C60;
extern S_4E5920_B D_001A4C20;
extern V4_4E5920 D_001E2AC0;
extern f32 func_0040BFB0(V4_4E5920 *, V4_4E5920 *);
extern void func_0040C2F8(V4_4E5920 *, V4_4E5920 *, void *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CFB0(f32, f32);
extern f32 func_0040BF68(V4_4E5920 *);
extern s32 func_00447CA0(O_4E5920 *);

f32 func_004E5920(O_4E5920 *obj, V4_4E5920 *dir, s32 *out, f32 lim, f32 lim2, f32 lim3, void *mat) {
    S_4E5920 *g;
    V4_4E5920 loc;
    V4_4E5920 t1;
    V4_4E5920 t2;
    V4_4E5920 t3;
    Q_4E5920 x, y;
    f32 d, a, b, yaw, m, pitch, r;

    *out = 0;
    loc = D_001A4C60;
    g = (S_4E5920 *)((u8 *)&D_001A4C60 - 0x80);
    if (g->w25C4 == 20 && g->f338 > 0.0f) {
        loc = g->v2F0;
    }
    d = func_0040BFB0(&loc, &obj->pos);
    if (lim < d) {
        *out = 1;
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(loc));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(y));
    func_0040C2F8(&t1, &t1, &D_001A4C20);
    t2 = *dir;
    func_0040C2F8(&t2, &t2, &D_001A4C20);
    a = func_0040C490(t1.x, t1.y);
    b = func_0040C490(t2.x, t2.y);
    yaw = func_0040CFB0(a, b);
    m = yaw;
    pitch = func_0040C490(func_0040BF68(&t1), t1.z);
    if (D_001A4C20.w2584 == 1 || D_001A4C20.w2584 == 29) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2AC0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(t3) : "j"(y));
        func_0040C2F8(&t3, &t3, mat);
        a = func_0040C490(t3.x, t3.y);
        pitch = func_0040C490(func_0040BF68(&t3), t3.z);
        m = pitch;
        yaw = a + pitch;
        if (pitch < a) {
            m = a;
        }
    }
    if (lim2 > 0.0f && lim2 < m) {
        *out = 1;
    }
    if (lim3 > 0.0f && lim3 < pitch) {
        *out = 1;
    }
    r = d + yaw * d;
    if (func_00447CA0(obj)) {
        r += lim * 0.8f;
    }
    return r;
}
/* localdecomp:end func_004E5920 */
