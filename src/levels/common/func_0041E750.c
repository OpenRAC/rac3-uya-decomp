#include "common.h"

/* localdecomp:start func_0041E750 */
typedef int Q_41E750 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_41E750;
extern s32 D_001E10E8;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001DFD8C;
extern u8 D_001DA1B0[];
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
void func_0041E750(s32 tu, s32 tv, unsigned long tex, s32 flag, s32 *col, f32 x, f32 y, f32 h, f32 wd, f32 ang) {
    V4_41E750 u;
    V4_41E750 w;
    V4_41E750 c;
    V4_41E750 p0;
    V4_41E750 p1;
    V4_41E750 p2;
    V4_41E750 p3;
    Q_41E750 z;
    u8 *r;
    u8 *p;
    u8 *q;
    s32 s, t;

    c.x = x;
    c.y = y;
    u.x = wd * func_0040C3E0(ang);
    u.y = wd * func_0040C3C8(ang);
    w.x = -h * func_0040C3C8(ang);
    w.y = h * func_0040C3E0(ang);
    if (flag != 0) {
        z = 0;
        __asm__ __volatile__(
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %2\n"
            "lqc2 $vf1, %7\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %2\n"
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            "lqc2 $vf1, %7\n"
            "lqc2 $vf2, %0\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %0\n"
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %1\n"
            "lqc2 $vf1, %6\n"
            "lqc2 $vf2, %1\n"
            "vsub.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %1\n"
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %3\n"
            "lqc2 $vf2, %3\n"
            "lqc2 $vf1, %6\n"
            "vsub.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %3\n"
            : "=m"(p0), "=m"(p1), "=m"(p2), "=m"(p3)
            : "m"(u), "m"(c), "m"(w), "m"(z));
    } else {
        __asm__ __volatile__(
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %3\n"
            "lqc2 $vf1, %6\n"
            "lqc2 $vf2, %3\n"
            "vsub.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %3\n"
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %2\n"
            "lqc2 $vf1, %6\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %2\n"
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %1\n"
            "lqc2 $vf1, %6\n"
            "lqc2 $vf2, %1\n"
            "vsub.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %1\n"
            "lqc2 $vf2, %4\n"
            "lqc2 $vf1, %5\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            "lqc2 $vf2, %0\n"
            "lqc2 $vf1, %6\n"
            "vadd.xyz $vf2, $vf2, $vf1\n"
            "sqc2 $vf2, %0\n"
            : "=m"(p0), "=m"(p1), "=m"(p2), "=m"(p3)
            : "m"(u), "m"(c), "m"(w));
    }
    *(s32 *)(D_001E10E8 + 0) = 0x10000008;
    *(s32 *)(D_001E10E8 + 4) = 0;
    *(s32 *)(D_001E10E8 + 8) = 0;
    *(s32 *)(D_001E10E8 + 0xC) = 0x50000008;
    r = (u8 *)D_001E10E8;
    D_001E10E8 = (s32)r + 0x10;
    *(Q_41E750 *)(r + 0x10) = *(Q_41E750 *)D_001DA1B0;
    p = (u8 *)D_001E10E8;
    q = p + 0x10;
    D_001E10E8 = (s32)q;
    s = tu << 4;
    t = tv << 20;
    *(unsigned long *)(p + 0x10) = tex;
    *(long *)(q + 8) = 348;
    *(long *)(q + 0x10) = col[0];
    *(long *)(q + 0x18) = 0;
    *(long *)(q + 0x20) = ((s32)p0.x + D_001D4BD0 - 8) | ((long)((s32)p0.y + D_001D4BD4 - 8) << 16) | ((long)D_001DFD8C << 32);
    *(long *)(q + 0x28) = col[1];
    *(long *)(q + 0x30) = s;
    *(long *)(q + 0x38) = ((s32)p1.x + D_001D4BD0 - 8) | ((long)((s32)p1.y + D_001D4BD4 - 8) << 16) | ((long)D_001DFD8C << 32);
    *(long *)(q + 0x40) = col[2];
    *(long *)(q + 0x48) = t;
    *(long *)(q + 0x50) = ((s32)p2.x + D_001D4BD0 - 8) | ((long)((s32)p2.y + D_001D4BD4 - 8) << 16) | ((long)D_001DFD8C << 32);
    *(long *)(q + 0x58) = col[3];
    *(long *)(q + 0x60) = t + s;
    *(long *)(q + 0x68) = ((s32)p3.x + D_001D4BD0 - 8) | ((long)((s32)p3.y + D_001D4BD4 - 8) << 16) | ((long)D_001DFD8C << 32);
    D_001E10E8 = D_001E10E8 + 0x70;
}
/* localdecomp:end func_0041E750 */
