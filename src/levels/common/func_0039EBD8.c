#include "common.h"

typedef int Q_39EBD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EBD8;

extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);
extern s32 func_004182B0(s32 a);
extern s32 func_004182E0(s32 lo, s32 hi);
extern f32 func_00418328(f32 lo, f32 hi);
extern f32 func_004183E0(void);
extern u8 *func_00442A78(V4_39EBD8 *pos, void *def, s32 life, s32 color, s32 a, s32 b, s32 c, f32 sx, f32 sy, f32 g, s32 d);
extern s32 D_001D66B0;
extern u8 *D_0021E2BC[];

void func_0039EBD8(u8 *m) {
    V4_39EBD8 pos;
    V4_39EBD8 off;
    u8 *v;
    u8 *p;
    f32 r;
    f32 base;
    f32 rad;
    f32 ang;
    f32 h;
    f32 s;
    s32 life;
    s32 color;
    s32 b8;

    v = *(u8 **)(m + 0x68);
    r = func_00418328(0.0f, *(f32 *)(v + 8));
    base = *(f32 *)(v + 0xC) * -0.79999995f + 0.9f;
    rad = base + (0.1f - base) * r;
    ang = func_004183E0();
    h = *(f32 *)(v + 8) - 0.5f;
    if (h < 0.0f) {
        h = 0.0f;
    }
    b8 = 0;
    *(Q_39EBD8 *)&off = 0;
    h *= 3.0f;
    h += r * 3.0f;
    off.x = rad * func_003E4B48(ang);
    off.y = rad * func_003E4B30(ang);
    off.z = h;
    pos = off;
    {
        Q_39EBD8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_39EBD8 *)(m + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(z));
    }
    life = func_004182E0(-10, 10) + 30;
    s = func_00418328(-0.1f, 0.1f) + 0.3f;
    color = (v[0x16] << 16) | (v[0x15] << 8) | v[0x14];
    p = func_00442A78(&pos, &D_001D66B0, life, color, func_004182B0(2) ? -1 : 1, 0x40, 0x20, s * 210000.0f, s * 210000.0f, 0.0011111111f, 0);
    if (p != 0) {
        b8 = p[8] + 0x20;
        p[2] = *D_0021E2BC[0];
    }
    p = func_00442A78(&pos, &D_001D66B0, life, 0xF7F7F7, func_004182B0(2) ? -1 : 1, 0x30, 0x30, s * 0.4f * 210000.0f, s * 0.4f * 210000.0f, 0.0011111111f, 0);
    if (p != 0) {
        p[2] = *D_0021E2BC[0];
        p[8] = b8;
    }
}
