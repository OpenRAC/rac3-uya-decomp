#include "common.h"

extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040BE90(f32 *, void *, f32);
extern void func_00404740(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern s32 D_001E10E8;

typedef int Q_3875A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3875A0;
extern s32 D_001D4BD0_003875A0;
extern s32 D_001D4BD4_003875A0;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040BE90(f32 *, void *, f32);
void func_00404740(f32 px, f32 py, f32 sx, f32 sy, f32 ang, s32 w, s32 h, long tex, s32 z, s32 rgba,
                   s32 fx, s32 fy, f32 ax, f32 ay) {
    V4_3875A0 a, b, c, t, p0, p1, p2, p3;
    s32 u0, u1, v0, v1;
    f32 bx, by, sn;
    long zz;
    u8 bfx = fx;
    u8 bfy = fy;
    if (bfx) {
        u0 = w << 4;
        u1 = 0x10;
    } else {
        u1 = w << 4;
        u0 = 0x10;
    }
    if (bfy) {
        v0 = h << 20;
        v1 = 0x100000;
    } else {
        v1 = h << 20;
        v0 = 0x100000;
    }
    c.x = px;
    c.y = py;
    sn = func_0040C3E0(ang);
    bx = 1.0f;
    by = bx - ay;
    bx = bx - ax;
    a.x = sy * sn;
    a.y = sy * func_0040C3C8(ang);
    b.x = sx * func_0040C3C8(ang);
    b.y = -sx * func_0040C3E0(ang);
    func_0040BE90(&t.x, &a, by);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(r1)); }
    func_0040BE90(&t.x, &b, bx);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p0));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(r1)); }
    func_0040BE90(&t.x, &a, by);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(r1)); }
    func_0040BE90(&t.x, &b, ax);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p1));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(r1)); }
    func_0040BE90(&t.x, &a, ay);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(r1)); }
    func_0040BE90(&t.x, &b, bx);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p2));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(r1)); }
    func_0040BE90(&t.x, &a, ay);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(r1)); }
    func_0040BE90(&t.x, &b, ax);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(p3));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(t));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(r2), "j"(r1));
      __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(r2)); }
    *(u32 *)(D_001E10E8 + 0) = 0x10000007;
    *(u32 *)(D_001E10E8 + 4) = 0;
    *(u32 *)(D_001E10E8 + 8) = 0;
    *(u32 *)(D_001E10E8 + 0xC) = 0x50000007;
    zz = (long)z << 32;
    {
        long *t2 = (long *)(D_001E10E8 + 0x10);
        D_001E10E8 = (s32)t2;
        t2[0] = 0xB400000000008001UL;
        t2[2] = tex;
        t2[1] = (0xA6A6A6A6UL << 11) | 0x106;
        t2[4] = rgba;
        t2[3] = 0x154;
        t2[5] = u0 | v0;
        t2[6] = ((s32)(p0.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p0.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[7] = u1 | v0;
        t2[8] = ((s32)(p1.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p1.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[9] = u0 | v1;
        t2[10] = ((s32)(p2.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p2.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[11] = u1 | v1;
        t2[12] = ((s32)(p3.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p3.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[13] = 0;
    }
    D_001E10E8 += 0x70;
}
