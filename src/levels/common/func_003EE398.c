#include "common.h"

/* localdecomp:start func_003EE398 */
typedef int Q_3EE398 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3EE398;
typedef struct {
    u8 pad[128];
} E_3EE398;
typedef struct {
    f32 nearDist;
    f32 farDist;
    u8 pad8[4];
    s32 vol;
    u8 pad10[8];
    u8 b18;
    u8 pad19[7];
} SND_3EE398;
typedef struct {
    s32 ids[4];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
} H_3EE398;
typedef struct {
    u8 pad0[8];
    H_3EE398 *h;
    u8 padC[4];
    u8 m10[0x30];
    V4_3EE398 pos;
    u8 m50[0x30];
} O_3EE398;
extern V4_3EE398 D_001E2A40;
extern u8 D_001A3190[];
extern E_3EE398 D_001A30B0[];
extern s32 D_001DFBEC;
extern void func_004A6E88(s32);
extern s32 func_004A74A0(s32, s32, void *, s32);
extern void func_004A7628(s32, s32);
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BF38(void *);
extern s32 func_0040BA90(s32 *);
extern s32 func_00440848(s32);

void func_003EE398(O_3EE398 *obj) {
    H_3EE398 *h = obj->h;
    V4_3EE398 d;
    V4_3EE398 v;
    V4_3EE398 w;
    SND_3EE398 *snd;
    s32 inside;
    s32 flags;
    s32 a, b, tmp;
    f32 k, t, dist, c, s, n;
    u8 *e;
    Q_3EE398 x, y, r;

    if (h->f2C != -1) {
        if (h->f1C != -1) {
            e = (u8 *)&D_001A30B0[h->f1C];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                func_004A6E88(h->f1C);
            }
        }
        h->f1C = -1;
        if (h->f20 != -1) {
            e = (u8 *)&D_001A30B0[h->f20];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                func_004A6E88(h->f20);
            }
        }
        tmp = h->f2C;
        h->f20 = -1;
        h->f24 = tmp;
        h->f2C = -1;
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(y));
    d.w = 0.0f;
    inside = 1;
    func_0040C2D0(&v, &d, obj->m50);
    if (v.x > 1.0f) {
        v.x = 1.0f;
        inside = 0;
    }
    if (v.x < -1.0f) {
        v.x = -1.0f;
        inside = 0;
    }
    if (v.y > 1.0f) {
        v.y = 1.0f;
        inside = 0;
    } else if (v.y < -1.0f) {
        v.y = -1.0f;
        inside = 0;
    }
    if (v.z > 1.0f) {
        v.z = 1.0f;
        inside = 0;
    } else if (v.z < -1.0f) {
        v.z = -1.0f;
        inside = 0;
    }
    snd = (SND_3EE398 *)((h->ids[h->f24] << 5) + D_001DFBEC);
    flags = 0;
    if (snd->b18) {
        flags |= 4;
    }
    if (inside == 1) {
        if (h->f1C != -1) {
            e = (u8 *)&D_001A30B0[h->f1C];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                func_004A6E88(h->f1C);
            }
        }
        h->f1C = -1;
        if (h->f20 != -1) {
            e = (u8 *)&D_001A30B0[h->f20];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                return;
            }
        }
        if (func_0040BA90(&h->f18) != 0) {
            h->f20 = func_004A74A0(h->ids[h->f24], flags | 0x110, obj, 0x400);
            if (h->f14 > 0) {
                h->f18 = (f32)(h->f10 + func_00440848(h->f14 - h->f10)) * 60.0f;
            }
        }
        return;
    }
    t = 1.0f;
    func_0040C2D0(&v, &v, obj->m10);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(w) : "j"(x));
    dist = func_0040BF38(&w);
    if (snd->farDist < dist) {
        if (h->f1C != -1) {
            e = (u8 *)&D_001A30B0[h->f1C];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                func_004A6E88(h->f1C);
            }
        }
        h->f1C = -1;
        if (h->f20 != -1) {
            e = (u8 *)&D_001A30B0[h->f20];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                func_004A6E88(h->f20);
            }
        }
        h->f20 = -1;
    } else {
        t = dist * (t / (snd->farDist - snd->nearDist));
    }
    if (t < 0.2f) {
        s = (0.2f - t) * 5.0f;
        c = 1.0f - s;
        __asm__("nop\n\tnop\n\tsqrt.s %0, %1\n\tnop\n\tnop" : "=f"(n) : "f"(s * s + c * c));
        k = (f32)snd->vol / n;
        b = s * k;
        a = c * k;
        if (h->f20 != -1) {
            e = (u8 *)&D_001A30B0[h->f20];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                goto play;
            }
        }
        h->f20 = func_004A74A0(h->ids[h->f24], flags | 0x110, obj, 0x400);
play:
        func_004A7628(h->f20, b);
    } else {
        if (h->f20 != -1) {
            e = (u8 *)&D_001A30B0[h->f20];
            if (*(void **)(e + 256) == obj && e[208] != 0) {
                func_004A6E88(h->f20);
                h->f20 = -1;
            }
        }
        a = (f32)snd->vol * (1.0f - t);
    }
    if (h->f1C != -1) {
        e = (u8 *)&D_001A30B0[h->f1C];
        if (*(void **)(e + 256) == obj && e[208] != 0) {
            goto near;
        }
    }
    if (a > 0) {
        h->f1C = func_004A74A0(h->ids[h->f24], flags | 0x10, obj, 0x400);
    }
near:
    if (h->f1C != -1) {
        *(Q_3EE398 *)(D_001A3190 + (h->f1C << 7)) = *(Q_3EE398 *)&v;
    }
    func_004A7628(h->f1C, a);
}
/* localdecomp:end func_003EE398 */
