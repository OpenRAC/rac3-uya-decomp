#include "common.h"

typedef int u128_312AE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_312AE8;
typedef struct {
    u8 pad[16];
    V4_312AE8 m16;
    V4_312AE8 v32;
    u8 pad48[8];
    s32 i56;
    f32 f60;
    s32 i64;
    s32 i68;
} W_312AE8;
typedef struct {
    V4_312AE8 v0;
    V4_312AE8 v16;
    f32 f32_;
    f32 f36;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f52;
    f32 f56;
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f72;
    f32 f76;
    s32 i80;
    s32 i84;
    s32 i88;
    s32 i92;
    s32 i96;
    s32 i100;
    s32 i104;
    s32 i108;
    s32 i112;
    s32 i116;
    s32 i120;
    W_312AE8 *w;
} E_312AE8;
extern E_312AE8 *D_001E17B4;
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern void func_0040CCA0(V4_312AE8 *, V4_312AE8 *, W_312AE8 *, f32);
extern void func_0040C0F0(V4_312AE8 *, V4_312AE8 *, f32);

/* localdecomp:start func_00312AE8 */
E_312AE8 *func_00312AE8(W_312AE8 *own, s32 type, V4_312AE8 *pos, f32 scale) {
    V4_312AE8 a;
    V4_312AE8 b;
    u128_312AE8 x, y;
    E_312AE8 *e;
    s32 i;
    s32 v0, v1, v2, v3;
    f32 f;

    for (i = 0; i < 320; i++) {
        if (D_001E17B4[i].w != 0) {
            continue;
        }
        switch (type) {
        case 0:
            own->i64++;
            if (own->i64 == 150) {
                own->i64--;
                return 0;
            }
            break;
        case 1:
            own->i68++;
            if (own->i68 == 150) {
                own->i68--;
                return 0;
            }
            break;
        }
        e = &D_001E17B4[i];
        e->w = own;
        own->i56++;
        v0 = func_00440878(95, 127);
        e->i120 = type;
        e->i96 = v0;
        e->i92 = v0;
        if (type == 0) {
            f = func_00440978();
            func_0040CCA0(&e->v16, &own->m16, own, f);
            e->f60 = e->f56 = own->f60 * func_004408C0(0.0f, 1.25f);
            e->f64 = 0.0f;
            v1 = func_00440878(0, 13);
            e->i108 = (v1 << 16) + (v1 << 8) + v1;
            e->f72 = e->f68 = func_004408C0(0.25f, 0.349999994f);
            f = func_004408C0(0.75f, 1.0f);
            e->f36 = 0.0f;
            e->f76 = f;
            e->i88 = e->i84 = func_00440878(100, 120);
            *(u128_312AE8 *)&e->v0 = *(u128_312AE8 *)&e->w->v32;
            func_0040C0F0(&a, &e->v16, func_004408C0(0.150000006f, 0.75f));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->v0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(e->v0) : "j"(y));
            e->i112 = 2;
            e->f48 = 0.0f;
        } else if (type == 1) {
            f = func_00440978();
            func_0040CCA0(&e->v16, &own->m16, own, f);
            e->f64 = e->f60 = e->f56 = 0.0f;
            v2 = func_00440878(0, 13);
            e->i108 = (v2 << 16) + (v2 << 8) + v2;
            e->f72 = e->f68 = func_004408C0(0.25f, 0.5f);
            e->f76 = func_004408C0(1.0f, 1.5f);
            e->f36 = func_004408C0(0.0666666701f, 0.0833333358f);
            e->i88 = e->i84 = func_00440878(100, 120);
            *(u128_312AE8 *)&e->v0 = *(u128_312AE8 *)pos;
            e->i112 = 2;
            e->f48 = 0.0f;
        } else if (type == 2) {
            func_0040CCA0(&e->v16, &own->m16, own, scale);
            e->f64 = e->f60 = e->f56 = 0.0f;
            v3 = func_00440878(1, 10);
            e->i108 = (v3 << 16) + (v3 << 8) + v3;
            e->f72 = e->f68 = func_004408C0(0.150000006f, 0.25f) * 0.5f;
            f = func_004408C0(0.5f, 0.800000012f) * 1.14999998f;
            e->f36 = 0.0583333373f;
            e->f76 = f;
            e->i88 = e->i84 = 90;
            func_0040C0F0(&a, (V4_312AE8 *)e->w, 0.200000003f);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->w->v32));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(e->v0) : "j"(y));
            func_0040C0F0(&b, &e->v16, 0.75f);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->v0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(e->v0) : "j"(x));
            e->f48 = func_00440918(0.0523598827f, 0.104719765f);
            e->i112 = type;
        }
        e->i104 = e->i100 = 0x103080;
        e->f32_ = 0.000555555569f;
        e->f44 = e->f40 = func_00440918(0.314159274f, 0.356338084f);
        e->f52 = func_00440978();
        e->i116 = 0;
        return e;
    }
    return 0;
}
/* localdecomp:end func_00312AE8 */
