#include "common.h"

/* localdecomp:start func_003676F0 */
typedef int Q_3676F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3676F0;
typedef struct { V4_3676F0 r0, r1, r2, r3; } M_3676F0;
typedef struct {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 w12;
    s32 w16;
    u8 pad20[12];
    V4_3676F0 v32;
    V4_3676F0 v48;
} P_3676F0;

extern s32 D_001DFBC0;
extern f32 D_001E1CA8;
extern f32 func_0040CFE8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040D020(s32, s32, f32);
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);
extern void func_0040C658(void *, void *);
extern f32 func_0040CF58(f32);
extern void func_0040C9B0(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_00409A50(void *, s32, f32, s32, s32, s32);

void func_003676F0(P_3676F0 *p) {
    V4_3676F0 rot;
    V4_3676F0 d;
    M_3676F0 m;
    M_3676F0 ma;
    M_3676F0 mb;
    f32 t;
    f32 ang;
    s32 col;

    col = func_0040D020(p->w8, p->w12, (func_0040C3E0(func_0040CFE8((f32)D_001DFBC0, 135.0f) / 135.0f * 6.2831855f) + 1.0f) * 0.5f);
    t = func_0040CFE8((f32)D_001DFBC0, p->f4 * 60.0f) / (p->f4 * 60.0f);
    ang = func_0040CFE8((f32)D_001DFBC0, p->f4 * 60.0f * 10.0f) / (p->f4 * 60.0f * 10.0f) * 6.2831855f;
    {
        Q_3676F0 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v48));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v32));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    }
    rot.x = 0.0f;
    rot.y = -func_0040C490(func_0040BF68(&d), d.z) + 1.5707964f;
    rot.z = func_0040C490(d.x, d.y);
    rot.w = 1.0f;
    func_0040C658(&ma, &rot);
    __asm__("sq $0, %0" : "=m"(rot));
    rot.z = func_0040CF58(ang);
    func_0040C658(&mb, &rot);
    func_0040C9B0(&m, &ma, &mb);
    m.r3 = p->v32;
    func_0040BE90(&m.r0, &m.r0, D_001E1CA8);
    func_0040BE90(&m.r1, &m.r1, D_001E1CA8);
    func_0040BE90(&m.r2, &m.r2, D_001E1CA8);
    func_00409A50(&m, p->w0, t, col, p->w16, 1);
    t += 0.5f;
    rot.z = func_0040CF58(-ang);
    func_0040C658(&mb, &rot);
    func_0040C9B0(&m, &ma, &mb);
    m.r3 = p->v32;
    func_0040BE90(&m.r0, &m.r0, D_001E1CA8);
    func_0040BE90(&m.r1, &m.r1, D_001E1CA8);
    func_0040BE90(&m.r2, &m.r2, D_001E1CA8);
    func_00409A50(&m, p->w0, t, col, p->w16, 1);
}
/* localdecomp:end func_003676F0 */
