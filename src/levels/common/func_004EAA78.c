#include "common.h"

/* localdecomp:start func_004EAA78 */
typedef int Q_4EAA78 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4EAA78;
typedef struct {
    u8 pad0[152];
    f32 f152;
    u8 pad156[244];
    V4_4EAA78 v400;
    f32 f416;
    u8 pad420[12];
    f32 f432;
    u8 pad436[4736];
    s16 h5172;
    u8 b5174;
    u8 b5175;
    u8 pad5176[632];
    s32 i5808;
    u8 pad5812[2988];
    f32 f8800;
    f32 f8804;
    u8 pad8808[856];
    u8 pad9664[52];
    u8 b9716;
    u8 pad9717[579];
    f32 f10296;
} D_4EAA78;
typedef struct {
    u8 pad0[24];
    f32 f24;
    u8 pad28[868];
    V4_4EAA78 v896;
} E_4EAA78;
typedef struct {
    V4_4EAA78 v0;
    u8 pad16[9248];
    u8 *p9264;
} F_4EAA78;
extern D_4EAA78 D_001A4BE0;
extern F_4EAA78 D_001A4D70;
extern E_4EAA78 D_001E2AC0;
extern f32 func_0040BF68(V4_4EAA78 *);
extern void func_0040BED8(V4_4EAA78 *, V4_4EAA78 *, f32);
extern f32 func_0050CD10(void);
extern void func_0040C2D0(V4_4EAA78 *, V4_4EAA78 *, void *);
extern f32 func_0040C490(f32, f32);
extern s32 func_0045D358(s32, s32, s32, s32);
extern f32 func_0040CFB0(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_0050D530(V4_4EAA78 *, V4_4EAA78 *, f32);
extern void func_0040C0F0(V4_4EAA78 *, V4_4EAA78 *, f32);

void func_004EAA78(s32 mode, f32 scale) {
    V4_4EAA78 v;
    V4_4EAA78 t;
    f32 ang;
    f32 len;
    f32 zero;
    s32 dir;

    v.x = D_001A4BE0.f8800;
    v.y = -D_001A4BE0.f8804;
    if (mode == 1) {
        f32 a, b;
        __asm__("abs.s %0, %1" : "=f"(a) : "f"(v.y));
        if (a > 0.7f) {
            __asm__("abs.s %0, %1" : "=f"(b) : "f"(v.x));
            if (b < 0.12f) {
                v.x = 0.0f;
            }
        }
        if (__builtin_fabsf(v.x) > 0.7f && __builtin_fabsf(v.y) < 0.12f) {
            v.y = 0.0f;
        }
    }
    len = func_0040BF68(&v);
    if (len > 1.0f) {
        func_0040BED8(&v, &v, len);
    }
    if (v.x == 0.0f && v.y == 0.0f) {
        D_001A4BE0.f432 = 0.0f;
        if (D_001A4BE0.b9716 != 0) {
            D_001A4BE0.f416 = func_0050CD10();
        } else {
            D_001A4BE0.f416 = D_001A4BE0.f152;
        }
        *(Q_4EAA78 *)&t = 0;
        t.x = 1.0f;
        func_0040C2D0(&D_001A4D70.v0, &t, D_001A4D70.p9264 + 192);
        return;
    }
    D_001A4BE0.f416 = func_0040C490(-v.y, -v.x);
    if (D_001A4BE0.h5172 != 0 || (D_001A4BE0.i5808 == 1 && func_0045D358(40, 2, 0, 0) != 0)) {
        dir = 2;
        ang = func_0040C490(v.x, v.y);
        if (func_0040CFB0(ang, 1.5707964f) < 0.7853982f) {
            dir = 3;
        } else if (func_0040CFB0(ang, 0.0f) < 0.7853982f) {
            dir = 1;
        } else if (func_0040CFB0(ang, 3.1415927f) < 0.7853982f) {
            dir = 0;
        }
        D_001A4BE0.b5175 = dir;
        if (dir == 3 && D_001A4BE0.f10296 > 0.15f) {
            D_001A4BE0.b5174 = 1;
        } else {
            D_001A4BE0.b5174 = 0;
        }
    }
    zero = 0.0f;
    D_001A4BE0.f416 = func_0040CEC8(D_001A4BE0.f416, D_001E2AC0.f24);
    {
        f32 x = v.x;
        f32 y = v.y;
        v.w = zero;
        v.z = zero;
        v.y = -x;
        v.x = -y;
    }
    func_0040C2D0(&D_001A4BE0.v400, &v, &D_001E2AC0.v896);
    func_0050D530(&D_001A4BE0.v400, &D_001A4BE0.v400, zero);
    func_0040C0F0(&D_001A4BE0.v400, &D_001A4BE0.v400, 1.0f);
    D_001A4BE0.f432 = scale * func_0040BF68(&v);
}
/* localdecomp:end func_004EAA78 */
