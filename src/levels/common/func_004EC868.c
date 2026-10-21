#include "common.h"

/* localdecomp:start func_004EC868 */
typedef int Q_4EC868 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4EC868;
typedef struct {
    u8 p0[32];
    V4_4EC868 v20;
    u8 p30[80];
    V4_4EC868 pos;
    u8 p90[342];
    s16 h1E6;
    u8 p1E8[8];
    s16 h1F0;
    u8 p1F2[38];
    s16 h218;
    u8 p21A[54];
    V4_4EC868 v250;
    V4_4EC868 v260;
    f32 f270;
    f32 f274;
    u8 p278[12];
    f32 f284;
    u8 p288[4];
    s32 i28C;
    u8 p290[23];
    u8 b2A7;
    u8 p2A8[56];
    V4_4EC868 v2E0;
    u8 p2F0[8912];
    u8 *p25C0;
    u8 p25C4[8];
    s32 i25CC;
    u8 p25D0[20];
    u8 b25E4;
    u8 p25E5[15];
    u8 b25F4;
    u8 p25F5[657];
    s16 h2886;
} S_4EC868;
extern S_4EC868 D_001A4BE0;
extern V4_4EC868 D_001EAAB0;
typedef struct {
    V4_4EC868 pos;
    u8 p10[500];
    f32 f204;
} P_4EC868;
extern P_4EC868 D_001A4C60;
extern s32 D_001D673C;
extern void func_0050E4B8(void);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0050D2A8(void *, void *, f32);
extern void func_0050D110(void *, s32, f32, f32, f32);
extern s32 func_003F9498(void *, s32, f32, u8 *);
extern s32 func_003FA2D8(void *, s32, f32, u8 *, f32);
extern s32 func_003FBAF8(void *, s32, f32);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);

#define POS_4EC868 D_001A4C60.pos

s32 func_004EC868(s32 arg0) {
    V4_4EC868 saved;
    V4_4EC868 delta;
    V4_4EC868 tmp;
    Q_4EC868 a, b;
    s32 facing;
    s32 i;
    s32 hit;
    f32 f;

    if (D_001A4BE0.h1F0 != 0) {
        return 1;
    }
    __asm__("sq $0,%0" : "=m"(delta));
    saved = D_001A4BE0.pos;
    if (D_001A4BE0.h2886 != 0) {
        func_0050E4B8();
        D_001A4BE0.h2886 = 0;
    }
    facing = 0;
    if (func_0040BEF8(&D_001A4BE0.v20, &D_001A4BE0.v2E0) > -0.92f) {
        facing = 1;
    }
    switch (D_001A4BE0.i25CC) {
    case 17:
        break;
    case 15:
        __asm__("sq $0,%0" : "=m"(delta));
        delta.z = 0.8f;
        func_0040C2D0(&delta, &delta, D_001A4BE0.p25C0 + 192);
        break;
    default:
        if (D_001A4BE0.b25F4 != 0 || D_001A4BE0.h218 != 0 || facing) {
            if (D_001A4BE0.b25E4 == 2) {
                func_0050D2A8(&delta, &delta, 5.0f);
            } else if (D_001A4BE0.b25F4 == 1 || D_001A4BE0.h218 != 0) {
                func_0050D110(&delta, 0, 0.0f, 0.0f, 0.6f);
            } else if (D_001D673C != 0) {
                func_0050D2A8(&delta, &delta, 0.77f);
            } else {
                func_0050D110(&delta, 0, 0.0f, 0.0f, D_001A4BE0.f274);
            }
        } else {
            delta.z = D_001A4BE0.f274;
        }
        break;
    }
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(delta));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(POS_4EC868));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(POS_4EC868) : "j"(a));
    for (i = 0; i < 8; i++) {
        S_4EC868 *d = &D_001A4BE0;
        if (d->i25CC == 17) {
            if (func_003F9498(&D_001A4BE0.pos, 36, 0.6f, D_001A4BE0.p25C0) == 0) {
                break;
            }
        } else if (d->i25CC == 15) {
            if (func_003F9498(&d->pos, 36, 0.45f, d->p25C0) == 0) {
                break;
            }
        } else {
            V4_4EC868 *pos;
            if (d->b25F4 != 0 || facing) {
                pos = &d->pos;
                hit = func_003F9498(pos, 36, d->f284, d->p25C0);
                if (d->h1E6 == 0) {
                    hit |= func_003FBAF8(pos, 0, d->f284);
                }
            } else {
                f = d->f270 - d->f274;
                if (f < 0.05f) {
                    f = 0.05f;
                }
                pos = &d->pos;
                hit = func_003FA2D8(pos, 36, d->f284, d->p25C0, f);
                if (d->h1E6 == 0) {
                    hit |= func_003FBAF8(pos, 0, d->f284);
                }
            }
            if (hit == 0) {
                break;
            }
        }
        {
            Q_4EC868 *src = (Q_4EC868 *)&D_001EAAB0;
            Q_4EC868 *dst = (Q_4EC868 *)&POS_4EC868;
            S_4EC868 *dd = (S_4EC868 *)((u8 *)dst - 128);
            Q_4EC868 qa = src[0];
            Q_4EC868 qb = src[1];
            Q_4EC868 qc = src[-1];
            s32 w = *(s32 *)((u8 *)src - 24);
            dst[29] = qb;
            dst[30] = qc;
            dd->b2A7 = 1;
            dd->i28C = w;
            dst[0] = qa;
        }
    }
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(delta));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(POS_4EC868));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(POS_4EC868) : "j"(a));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(saved));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(POS_4EC868));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(a));
    f = func_0040BF38(&tmp);
    if (D_001A4C60.f204 * 3.0f < f) {
        if (arg0 == 15) {
            if (tmp.x > 512.0f) {
                tmp.x = 512.0f;
            } else if (tmp.x < -512.0f) {
                tmp.x = -512.0f;
            }
            if (tmp.y > 512.0f) {
                tmp.y = 512.0f;
            } else if (tmp.y < -512.0f) {
                tmp.y = -512.0f;
            }
            if (tmp.z > 512.0f) {
                tmp.z = 512.0f;
            } else if (tmp.z < -512.0f) {
                tmp.z = -512.0f;
            }
            func_0040C0F0(&tmp, &tmp, D_001A4BE0.f284);
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(saved));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(tmp));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(D_001A4BE0.pos) : "j"(a));
        }
        return -1;
    }
    return 1;
}
/* localdecomp:end func_004EC868 */
