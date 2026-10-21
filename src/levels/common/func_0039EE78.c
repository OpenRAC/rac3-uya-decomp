#include "common.h"

/* localdecomp:start func_0039EE78 */
typedef int Q_39EE78 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EE78;
typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[0xC];
    u8 f14;
    u8 f15;
    u8 f16;
    u8 pad17;
    u8 f18;
} S_39EE78;
typedef struct {
    u8 pad0[0x164];
    u8 *f164;
} G_39EE78;
extern u8 *D_001DEA1C;
extern G_39EE78 D_0021E158;
extern f32 func_003E4B48(f32);
extern f32 func_003E4B30(f32);
extern f32 func_00418328(f32, f32);
extern void func_003E4858(V4_39EE78 *, V4_39EE78 *, f32);
extern s32 func_004182E0(s32, s32);
extern s32 func_004182B0(s32);
extern u8 *func_00442A78(V4_39EE78 *, V4_39EE78 *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_003E5630(f32, f32);
void func_0039EE78(u8 *o) {
    V4_39EE78 v;
    V4_39EE78 t;
    S_39EE78 *s = *(S_39EE78 **)(o + 0x68);
    u8 *p;
    u8 *e;
    s32 i;
    s32 c;
    s32 col;
    s32 sg;
    s32 b;
    f32 ang;
    f32 size;
    f32 life;
    Q_39EE78 x, y, r;
    p = D_001DEA1C + ((s->f18 != 0 ? s->f4 : s->f0) << 8);
    ang = 0.0f;
    for (i = 0; i < 40; i++) {
        *(Q_39EE78 *)&t = 0;
        b = 0;
        t.x = func_003E4B48(ang) * 0.4f;
        t.y = func_003E4B30(ang) * 0.4f;
        t.z = 1.75f;
        v = t;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_39EE78 *)(p + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
        v.z = 0.0f;
        func_003E4858(&v, &v, (func_00418328(-1.0f, 1.0f) + 10.0f) * 0.016666668f);
        c = func_004182E0(0xF, 0x19);
        size = func_00418328(-0.1f, 0.1f) + 0.5f;
        life = func_00418328(-4.0f, 4.0f) + 15.0f;
        col = (s->f16 << 16) | (s->f15 << 8) | s->f14;
        sg = func_004182B0(2) ? -1 : 1;
        e = func_00442A78(&t, &v, c, col, sg, 0x40, 0x20, size * 210000.0f, size * 210000.0f, life * 0.00027777778f, 0);
        if (e != 0) {
            b = e[8] + 0x20;
            e[2] = *D_0021E158.f164;
        }
        sg = func_004182B0(2) ? -1 : 1;
        e = func_00442A78(&t, &v, c, 0xF7F7F7, sg, 0x30, 0x30, size * 0.4f * 210000.0f, size * 0.4f * 210000.0f, life * 0.00027777778f, 0);
        if (e != 0) {
            e[2] = *D_0021E158.f164;
            e[8] = b;
        }
        ang = func_003E5630(ang, 0.15707964f);
    }
}
/* localdecomp:end func_0039EE78 */
