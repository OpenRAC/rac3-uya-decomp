#include "common.h"

/* localdecomp:start func_0041EB48 */
extern u32 *D_001E10E8;
extern s32 D_001DFD8C;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

typedef int Q_392DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392DD8;
extern u32 *D_001E10E8;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001DFD8C;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
void func_0041EB48(f32 x, f32 y, f32 w, f32 h, f32 ang, s32 tw, s32 th, s32 tex) {
    V4_392DD8 a, b, c, p0, p1, p2, p3;
    unsigned long *q;
    c.x = x;
    c.y = y;
    a.x = h * func_0040C3E0(ang);
    a.y = h * func_0040C3C8(ang);
    b.x = -w * func_0040C3C8(ang);
    b.y = w * func_0040C3E0(ang);
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p1));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p2));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    {
        Q_392DD8 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p3));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    D_001E10E8[0] = 0x10000007;
    D_001E10E8[1] = 0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000007;
    q = (unsigned long *)(D_001E10E8 + 4);
    D_001E10E8 = (u32 *)q;
    q[0] = 0xB400000000008001UL;
    q[1] = 0x53535353106UL;
    q[2] = tex;
    q[3] = 0x154;
    q[4] = 0x807F7F7F;
    q[5] = tw << 4;
    q[6] = (unsigned long)(((s32)p0.x + D_001D4BD0 - 8) | ((long)((s32)p0.y + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((s32)p1.x + D_001D4BD0 - 8) | ((long)((s32)p1.y + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[9] = 0;
    q[10] = (unsigned long)(((s32)p2.x + D_001D4BD0 - 8) | ((long)((s32)p2.y + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[11] = th << 20;
    q[12] = (unsigned long)(((s32)p3.x + D_001D4BD0 - 8) | ((long)((s32)p3.y + D_001D4BD4 - 8) << 16)) | ((long)D_001DFD8C << 32);
    q[13] = 0;
    D_001E10E8 += 0x1C;
}
/* localdecomp:end func_0041EB48 */
