#include "common.h"

/* localdecomp:start func_004C06E0 */
typedef int Q_4C06E0 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_4C06E0;

typedef struct {
    u8 pad0[0xF0];
    V4_4C06E0 vF0;
    u8 pad100[0x290 - 0x100];
    s32 w290;
    u8 pad294[0x25C0 - 0x294];
    s32 w25C0;
} P_4C06E0;

typedef struct {
    u8 pad0[0x18];
    s32 w18;
    s32 w1C;
    u8 pad20[0x40 - 0x20];
    V4_4C06E0 v40;
} T_4C06E0;

extern f32 func_004DD660(V4_4C06E0 *v);
extern void func_004DD340(V4_4C06E0 *out, f32 x, f32 y, f32 z, s32 n);
extern f32 func_003E4690(V4_4C06E0 *v);
extern void func_003E4858(V4_4C06E0 *out, V4_4C06E0 *in, f32 s);
extern void func_004DD760(V4_4C06E0 *out, V4_4C06E0 *in, f32 y);
extern void func_003E45B8(V4_4C06E0 *out, V4_4C06E0 *in, f32 s);
extern s32 func_003D1388(V4_4C06E0 *a, V4_4C06E0 *b, s32 c, s32 d, s32 e);
extern s32 func_003D5670(void);
extern f32 func_004DDAA0(V4_4C06E0 *v);
extern f32 func_003E4620(V4_4C06E0 *a, V4_4C06E0 *b);
extern V4_4C06E0 D_001A4CD0[];
extern P_4C06E0 D_001A4BE0;
extern s32 D_001E80DC[];
extern T_4C06E0 D_001E80C0;

void func_004C06E0(s32 force) {
    V4_4C06E0 off0;
    V4_4C06E0 dst0;
    V4_4C06E0 off1;
    V4_4C06E0 dst1;
    Q_4C06E0 x, y;
    Q_4C06E0 z, w;
    V4_4C06E0 *pl;
    f32 r;
    f32 s;
    f32 t;
    f32 dot;
    s32 hit;

    if (func_004DD660(D_001A4CD0) < 0.0016666668f) {
        return;
    }
    pl = (V4_4C06E0 *)((u8 *)D_001A4CD0 - 0xF0);
    r = 0.395f;
    s = 0.5f;
    if ((u32)(*(s32 *)((u8 *)pl + 0x25CC) - 17) < 2) {
        r = 0.0f;
        s = 0.7f;
    }
    func_004DD340(&off0, 0.0f, 0.0f, r, 1);
    func_004DD340(&off1, 0.0f, 0.0f, r * 0.3f, 1);
    if (force != 0 || func_003E4690(D_001A4CD0) < 0.01f) {
        func_003E4858(&dst0, pl, s);
        func_003E4858(&dst1, pl, s * 1.4f);
    } else {
        func_004DD760(&dst0, D_001A4CD0, 0.0f);
        func_003E4858(&dst0, &dst0, s);
        func_003E45B8(&dst1, &dst0, 1.4f);
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(off0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(dst0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(dst0) : "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(z) : "m"(dst1));
    __asm__("lqc2 %0, %1" : "=j"(w) : "m"(off1));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(z), "j"(w));
    __asm__("sqc2 %1, %0" : "=m"(dst1) : "j"(z));
    hit = -1;
    if (func_003D1388(&off1, &dst1, 2, D_001A4BE0.w25C0, 0) != 0 && D_001E80DC[0] > 0) {
        hit = func_003D5670();
    }
    t = 0.0f;
    if (func_003D1388(&off0, &dst0, 2, D_001A4BE0.w25C0, 0) != 0 && D_001E80C0.w1C > 0) {
        t = func_004DDAA0(&D_001E80C0.v40);
    }
    if (t >= 0.87266463f || hit == 8 || hit == 12) {
        D_001A4BE0.w290 = D_001E80C0.w18;
        func_004DD760(&D_001E80C0.v40, &D_001E80C0.v40, 0.0f);
        func_003E4858(&D_001E80C0.v40, &D_001E80C0.v40, 1.0f);
        dot = func_003E4620(&D_001E80C0.v40, &D_001A4BE0.vF0);
        if (dot < 0.0f) {
            func_003E45B8(&D_001E80C0.v40, &D_001E80C0.v40, -dot);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E80C0.v40));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4BE0.vF0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(D_001A4BE0.vF0) : "j"(y));
        }
    }
}
/* localdecomp:end func_004C06E0 */
