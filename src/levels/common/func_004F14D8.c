#include "common.h"

/* localdecomp:start func_004F14D8 */
typedef int Q_4F14D8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4F14D8;
typedef struct {
    u8 pad0[128];
    V4_4F14D8 v128;
    u8 pad144[96];
    V4_4F14D8 v240;
    u8 pad256[276];
    s16 h532;
    u8 pad534[344];
    s16 h878;
    u8 pad880[4361];
    u8 b5241;
    u8 pad5242[4422];
    s32 w9664;
    s32 w9668;
    u8 pad9672[4];
    s32 w9676;
    u8 pad9680[20];
    u8 b9700;
    u8 pad9701[595];
    f32 f10296;
} S_4F14D8;
typedef struct {
    u8 pad0[28];
    s32 w28;
    u8 pad32[32];
    V4_4F14D8 v64;
} T_4F14D8;
extern S_4F14D8 D_001A4BE0;
extern V4_4F14D8 D_001A4CD0;
typedef struct {
    V4_4F14D8 v;
    u8 pad16[9556];
    u8 b9572;
} U_4F14D8;
extern U_4F14D8 D_001A4C60;
extern T_4F14D8 D_001EAA80;
extern f32 func_0050D430(void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0050D5B0(void *, void *, f32);
extern void func_0050D1A0(void *, void *, f32);
extern void func_0050D530(void *, void *, f32);
extern void func_0050D2A8(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern f32 func_0050D870(void *);
extern void func_004ED3B8(f32);

s32 func_004F14D8(f32 a, f32 b, f32 c) {
    V4_4F14D8 t0, t1;
    Q_4F14D8 x, y;
    s32 ok;
    S_4F14D8 *g;
    S_4F14D8 *h;

    if (func_0050D430(&D_001A4CD0) == 0.0f) {
        return 0;
    }
    h = (S_4F14D8 *)((u8 *)&D_001A4CD0 - 240);
    if (h->f10296 > 0.5f && h->w9676 != 6 && h->h532 == 0 && h->b5241 == 0) {
        return 0;
    }
    g = &D_001A4BE0;
    if (g->h878 != 0 && g->w9668 != 128) {
        return 0;
    }
    func_0040BE90(&t0, &g->v240, a);
    if (b > 0.0f && func_0050D430(&t0) < b) {
        func_0050D5B0(&t0, &t0, 0.0f);
        func_0050D1A0(&t0, &t0, b);
    }
    func_0050D530(&t0, &t0, 0.0f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4C60.v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(x));
    t1 = t0;
    if (D_001A4C60.b9572 == 5) {
        func_0050D2A8(&t0, &t0, 1.0f);
    } else {
        func_0050D2A8(&t0, &t0, 0.3f);
    }
    c = -c;
    if (D_001A4BE0.b9700 == 2) {
        c = -0.7f;
    }
    func_0050D2A8(&t1, &t1, c);
    ok = 1;
    if (func_003F8448(&t0, &t1, 4, D_001A4BE0.w9664, 0) != 0 && D_001EAA80.w28 > 0) {
        if (func_0050D870(&D_001EAA80.v64) <= 0.87266463f || D_001A4BE0.w9668 == 128) {
            ok = 0;
        }
    }
    if (ok == 0) {
        return 0;
    }
    func_004ED3B8(0.0f);
    return 1;
}
/* localdecomp:end func_004F14D8 */
