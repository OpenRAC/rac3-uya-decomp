#include "common.h"

/* localdecomp:start func_004E39B8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_4E39B8;
typedef int Q_4E39B8 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_001EAA80[];
extern s32 D_001D545C;
extern f32 func_0050D4D8(void *);
extern void func_0050D530(Vec4_4E39B8 *, Vec4_4E39B8 *, f32);
extern void func_0050D5B0(Vec4_4E39B8 *, Vec4_4E39B8 *, f32);
extern void func_0050D180(Vec4_4E39B8 *, Vec4_4E39B8 *, f32);
extern s32 func_004E4550(Vec4_4E39B8 *, void *, s32);
extern s32 func_004E2628(s32, f32, f32);
extern void *func_00449388(s32);
extern void func_0050D060(Vec4_4E39B8 *, f32, f32, f32, s32);
extern s32 func_003F8448(Vec4_4E39B8 *, Vec4_4E39B8 *, s32, s32, s32);
extern s32 func_003FC730(void);
extern f32 func_0050D870(void *);
extern void func_0040C2F8(Vec4_4E39B8 *, void *, void *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CFB0(f32, f32);
extern f32 func_0040BFE8(void *, Vec4_4E39B8 *);
extern void func_0040C0F0(Vec4_4E39B8 *, void *, f32);
void func_004E39B8(void) {
    Vec4_4E39B8 a;
    Vec4_4E39B8 b;
    Vec4_4E39B8 c;
    u8 *p = D_001A4BE0;
    u8 *q;
    u8 *q1;
    u8 *g;
    s32 r;

    void *o;
    u8 *h;
    u8 *k;
    f32 f20;
    f32 f22;
    f32 half;

    if (*(f32 *)(p + 0x33C) < 0.4f) return;
    if (func_0050D4D8(p + 0xF0) < -0.33333334f) return;
    if (p[0x25F4] != 0) return;
    if (D_001D545C == 28) return;
    if (*(s32 *)(p + 0x528) != 0) {
        *(s32 *)(p + 0x1D4) = 0;
        return;
    }
    a = *(Vec4_4E39B8 *)(p + 0x80);
    b = *(Vec4_4E39B8 *)(p + 0x110);
    func_0050D530(&b, &b, 0.0f);
    half = 0.5f;
    func_0050D5B0(&b, &b, 20.0f);
    {
        Q_4E39B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(z));
    }
    func_0050D180(&a, &a, func_0050D4D8(p + 0xF0) * 20.0f - *(f32 *)(p + 0x4F0) * 20.0f * 20.0f * half);
    if (func_004E4550(&a, p + 0x90, 0) != 0) {
        *(s32 *)(p + 0x1D4) = 0;
        *(s16 *)(p + 0x210) = 22;
        return;
    }
    if (func_004E2628(0, 0.3f, 1.0f) == 0) return;
    o = 0;
    q1 = D_001EAA80;
    if (*(s32 *)(q1 + 0x18) != 0) {
        o = func_00449388(*(s32 *)(q1 + 0x18));
    }
    f20 = 1.7f;
    if (o != 0 && (*(s32 *)((u8 *)o + 0x3C) & 0x20)) {
        f20 = half;
    } else if (g = D_001A4BE0, *(s32 *)(g + 0x25C4) != 17) {
        if (g[0x2A5] == 0 || g[0x2A4] != 0) {
            f20 = 3.0f;
        }
    }
    func_0050D060(&a, 0.0f, 0.0f, f20, 1);
    h = D_001A4BE0;
    func_0050D060(&b, *(f32 *)(h + 0x284) + 1.4f, 0.0f, f20, 1);
    if (func_003F8448(&a, &b, 2, 0, 0) == 0) return;
    r = func_003FC730();
    if (r == 10 || r == 12) return;
    q = D_001EAA80;
    *(s32 *)(h + 0x2B4) = *(s32 *)(q + 0x18);
    if (func_0050D870(q + 0x40) < 1.3089969f) return;
    func_0040C2F8(&c, q + 0x40, h + 0x40);
    if (0.87266463f < func_0040CFB0(func_0040C490(c.x, c.y), 3.1415927f)) return;
    f22 = 0.72f;
    if (*(s32 *)(h + 0x25C4) == 17) f22 = 0.95f;
    func_0050D060(&a, 0.0f, 0.0f, 0.2f, 1);
    func_0050D060(&b, *(f32 *)(h + 0x284) + 1.4f, 0.0f, 0.2f, 1);
    if (func_003F8448(&a, &b, 2, 0, 0) == 0) return;
    if (f22 < func_0040BFE8(q + 0x20, &a)) return;
    *(Vec4_4E39B8 *)(h + 0x4B0) = *(Vec4_4E39B8 *)(q + 0x40);
    *(f32 *)(h + 0x4BC) = func_0040C490(*(f32 *)(q + 0x40), *(f32 *)(q + 0x44));
    *(f32 *)(h + 0x2860) = 5.0f;
    a = *(Vec4_4E39B8 *)(h + 0x260);
    func_0040C0F0(&b, q + 0x40, 10.0f);
    {
        Q_4E39B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(z));
    }
    if (func_003F8448(&a, &b, 2, 0, 0) != 0) {
        *(f32 *)(h + 0x2860) = func_0040BFE8(&a, &b);
    }
    if (*(s32 *)(h + 0x25CC) != 4 && *(s32 *)(h + 0x25D4) != 4 && *(s32 *)(h + 0x25E0) != 4) return;
    k = D_001A4BE0;
    if (*(s16 *)(k + 0x285C) != 0) {
        if (func_0040CFB0(*(f32 *)(k + 0x4CC), *(f32 *)(k + 0x4BC)) < 2.9670596f) return;
    }
    k[0x285E] = 0;
    if (r == 15) {
        k[0x285E] = 1;
    } else if (k[0x285F] != 0) {
        return;
    }
    {
        u8 *m = D_001A4BE0;
        if (*(s32 *)(m + 0x25C4) == 17) {
            *(s32 *)(m + 0x1D4) = 7;
        } else {
            *(s32 *)(m + 0x1D4) = 6;
        }
    }
}
/* localdecomp:end func_004E39B8 */
