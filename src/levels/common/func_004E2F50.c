#include "common.h"

/* localdecomp:start func_004E2F50 */
typedef int Q_4E2F50 __attribute__((mode(TI)));
typedef union {
    Q_4E2F50 q;
    struct { f32 x, y, z, w; } f;
} __attribute__((aligned(16))) V4_4E2F50;
typedef struct {
    u8 pad0[0x10];
    V4_4E2F50 v10;
} T_4E2F50;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0x28 - 0x14];
    u8 b28;
    u8 b29;
    u8 b2A;
} R_4E2F50;
typedef struct {
    u8 pad0[0x43];
    u8 b43;
} C_4E2F50;
typedef struct {
    u8 pad0[0x80];
    V4_4E2F50 v80;
    u8 pad90[0x98 - 0x90];
    f32 f98;
    u8 pad9C[0x1DC - 0x9C];
    s16 h1DC;
    u8 pad1DE[0xBD8 - 0x1DE];
    T_4E2F50 *pBD8;
    u8 padBDC[0x1430 - 0xBDC];
    s32 w1430;
    u8 pad1434[0x25C0 - 0x1434];
    C_4E2F50 *p25C0;
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 b25E9;
    u8 pad25EA[0x27FC - 0x25EA];
    T_4E2F50 *p27FC;
} G_4E2F50;
typedef struct {
    u8 pad0[0x114];
    f32 f114;
    u8 pad118[0x1C8 - 0x118];
    f32 f1C8;
    u8 pad1CC[0x274 - 0x1CC];
    f32 f274;
    f32 f278;
} X_4E2F50;

extern G_4E2F50 D_001A4BE0;
extern V4_4E2F50 D_001A4C60;
extern s32 D_001DFBC0;
extern T_4E2F50 *D_0021E8E0[];
extern X_4E2F50 D_002F4580;

extern R_4E2F50 *func_00440728(T_4E2F50 *);
extern f32 func_0040BFE8(void *, void *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CFB0(f32, f32);
extern f32 func_0040CF10(f32, f32);
extern void func_0050D110(void *, f32, f32, f32, s32);
extern void func_0050D180(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern void func_004E25F8(f32, f32);
extern void func_004E25E0(f32, f32);
extern void func_004E2610(f32, f32);

void func_004E2F50(void) {
    V4_4E2F50 a;
    V4_4E2F50 b;
    s32 s7;
    s32 st;
    f32 yaw;
    f32 pitch;

    s7 = 0;
    if (D_001A4BE0.pBD8 != 0) {
        s7 = D_001A4BE0.w1430 == 0;
    }
    st = D_001A4BE0.w25CC;
    if (st != 1 && st != 4 && st != 2 && st != 7 && st != 0) {
        D_001A4BE0.pBD8 = 0;
        D_001A4BE0.p27FC = 0;
        return;
    }
    if (D_001A4BE0.w25C4 == 46) {
        return;
    }
    if (D_001A4BE0.b25E9 != 0) {
        D_001A4BE0.p27FC = 0;
    }
    if (s7 == 0) {
        if (D_001A4BE0.p25C0->b43 == 74) {
            return;
        }
        if (D_001DFBC0 % 7 == 0) {
            s32 i;
            T_4E2F50 *o;
            T_4E2F50 *best;
            f32 bestd;
            f32 bestp;
            bestd = 100000000.0f;
            bestp = 0.0f;
            best = 0;
            for (i = 0; (o = D_0021E8E0[i]) != 0; i++) {
                R_4E2F50 *r = func_00440728(o);
                f32 d;
                f32 ang;
                f32 sc;
                f32 pr;
                f32 pt;
                G_4E2F50 *g;
                if (r == 0) {
                    continue;
                }
                d = func_0040BFE8(&D_001A4C60, &o->v10);
                if ((f32)r->b28 < d) {
                    continue;
                }
                g = (G_4E2F50 *)((u8 *)&D_001A4C60 - 0x80);
                ang = func_0040CFB0(func_0040C490(o->v10.f.x - g->v80.f.x, o->v10.f.y - g->v80.f.y), g->f98);
                if (1.5707964f < ang) {
                    continue;
                }
                pt = func_0040C490(func_0040BFE8(&o->v10, &D_001A4C60), g->v80.f.z - o->v10.f.z);
                __asm__("abs.s %0, %1" : "=f"(pt) : "f"(pt));
                if (0.87266463f < pt) {
                    continue;
                }
                sc = ang * d + d;
                if (o == g->p27FC) {
                    sc = sc - 1.5f;
                    if (sc < 0.0f) {
                        sc = 0.0f;
                    }
                }
                pr = (f32)r->b29;
                if (bestp < pr || sc < bestd) {
                    if (pr > bestp) {
                        bestp = pr;
                    }
                    bestd = sc;
                    best = o;
                }
            }
            D_001A4BE0.p27FC = best;
        }
        if (D_001A4BE0.p27FC != 0) {
            if (func_0040BFE8(&D_001A4BE0.v80, &D_001A4BE0.p27FC->v10) < 50.0f) {
                func_0050D110(&a, 0.0f, 0.0f, 1.2f, 1);
                b = D_001A4BE0.p27FC->v10;
                func_0050D180(&b, &b, 0.5f);
                if (func_003F8448(&a, &b, 2, 0, 0) != 0) {
                    D_001A4BE0.p27FC = 0;
                }
            }
        }
    }
    if (D_001A4BE0.p27FC != 0 || s7 != 0) {
        T_4E2F50 *t;
        R_4E2F50 *r;
        t = D_001A4BE0.p27FC;
        if (s7 != 0) {
            t = D_001A4BE0.pBD8;
        }
        a = t->v10;
        r = func_00440728(t);
        if (r != 0) {
            if (s7 != 0) {
                a.f.z += r->f10;
            } else {
                a.f.z += (f32)r->b2A * 0.125f;
            }
        }
        if (s7 != 0) {
            func_0050D110(&b, 0.5f, 0.0f, 0.55f, 1);
        } else {
            func_0050D110(&b, 0.3f, 0.0f, 0.85f, 1);
        }
        yaw = func_0040CF10(func_0040C490(a.f.x - b.f.x, a.f.y - b.f.y), D_001A4BE0.f98);
        pitch = func_0040C490(func_0040BFE8(&a, &b), b.f.z - a.f.z);
        if (1.0297443f < yaw) {
            yaw = 1.0297443f;
        } else if (yaw < -1.0297443f) {
            yaw = -1.0297443f;
        }
        if (0.61086524f < pitch) {
            pitch = 0.61086524f;
        }
        if (pitch < -0.43633232f) {
            pitch = -0.43633232f;
        }
        if (D_001A4BE0.h1DC >= 28) {
            if (0.29670596f < yaw) {
                yaw = 0.29670596f;
            } else if (yaw < -0.29670596f) {
                yaw = -0.29670596f;
            }
            pitch = 0.0f;
        }
        if (s7 != 0) {
            f32 c0 = 0.037f;
            f32 c1 = 0.3f;
            func_004E25F8(c0, c1);
            D_002F4580.f1C8 = yaw;
            func_004E25E0(c0, c1);
            D_002F4580.f114 = pitch;
        } else {
            func_004E2610(0.021f, 0.27f);
            D_002F4580.f274 = pitch;
            D_002F4580.f278 = yaw * 0.75f;
            func_004E25F8(0.014f, 0.3f);
            D_002F4580.f1C8 = D_002F4580.f278 * 0.25f;
        }
    }
    D_001A4BE0.pBD8 = 0;
}
/* localdecomp:end func_004E2F50 */
