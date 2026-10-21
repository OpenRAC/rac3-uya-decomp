#include "common.h"

/* localdecomp:start func_003D1920 */
typedef int Q_3D1920 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D1920;

extern s32 D_001DF9C0;
extern f32 func_0044FD38(f32, f32);
extern f32 func_0041D7E0(f32, f32);
extern f32 func_0041CCE0(f32);
extern f32 func_0041CCF8(f32);
extern void func_0041C768(void *, void *, f32);
extern f32 func_0044FCE0(f32, f32);
extern s32 func_0044FC98(s32, s32);
extern void func_00472E28(void *, void *, u32, s32, f32, s32);

void func_003D1920(u8 *o, u8 *v) {
    V4_3D1920 pos;
    V4_3D1920 vel;
    V4_3D1920 off;
    Q_3D1920 a, b, r;
    f32 t1, t2, t3, t4, t5;
    s32 c;
    u32 col;
    V4_3D1920 *vp;

    if (D_001DF9C0 & 1) {
        return;
    }
    *(f32 *)(v + 0x9C) = func_0041D7E0(*(f32 *)(v + 0x9C), func_0044FD38(0.052359879f, 0.104719758f));
    pos = *(V4_3D1920 *)(o + 0x10);
    pos.z += 1.0f;
    t1 = func_0041CCE0(*(f32 *)(v + 0x9C));
    pos.x += t1 * func_0044FD38(0.5f, 1.0f);
    t2 = func_0041CCF8(*(f32 *)(v + 0x9C));
    pos.y += t2 * func_0044FD38(0.5f, 1.0f);
    if (*(s32 *)(v + 0x90) != 0) {
        func_0041C768(&off, o + 0xC0, 3.0f);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(off));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(r));
    }
    t3 = func_0041CCE0(*(f32 *)(v + 0x9C));
    vel.x = t3 * (func_0044FCE0(0.5f, 2.0f) * 0.0166666675f);
    t4 = func_0041CCF8(*(f32 *)(v + 0x9C));
    vel.y = t4 * (func_0044FCE0(0.5f, 2.0f) * 0.0166666675f);
    vel.z = 0.0f;
    vel.z = func_0044FCE0(0.0333333351f, 0.0833333358f);
    c = func_0044FC98(0x10, 0x20);
    col = 0x80000000 | c << 16 | c << 8 | c;
    vp = &vel;
    t5 = func_0044FCE0(3.0f, 5.0f) * 210000.0f;
    func_00472E28(&pos, vp, col, 0x101010, t5, func_0044FC98(0x50, 0x78));
}
/* localdecomp:end func_003D1920 */
