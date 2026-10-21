#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { f32 v[4]; } F4;

extern F4 D_001D7F00;
extern f32 D_001DFBCC;
extern u8 D_001E2A40[];
extern s32 func_0040BAC0(void *);
extern s32 func_00444338(s32, s32, f32);
extern f32 func_0040BFB0(void *, void *);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern void func_00462578(void *, void *, s32, s32, f32, s32, s32);
extern void func_0045E580(void *);

/* localdecomp:start func_00462718 */
void func_00462718(u8 *s) {
    u8 *q;
    V4 pos;
    F4 t;
    s32 c;
    s32 a;
    f32 d;
    s32 c1;
    s32 c2;
    f32 r;
    s32 n;

    q = s + 32;
    t = D_001D7F00;
    if (*(s16 *)(q + 26) == 3 && D_001DFBCC > 0.95f) {
        func_0040BAC0(s + 10);
    }
    if (func_0040BAC0(s + 10) != 0) {
        goto kill;
    }
    c = func_00444338(*(s32 *)(q + 20), *(s32 *)(q + 16), (f32)*(s16 *)(s + 10) / (f32)*(s16 *)(q + 24));
    *(s32 *)(s + 4) = c;
    a = c >> 24;
    d = func_0040BFB0(s + 16, D_001E2A40);
    if (*(s16 *)(s + 10) < 6) {
        a = a * *(s16 *)(s + 10) / 6;
    }
    if (d < 4.0f) {
        goto kill;
    }
    if (d < 8.0f) {
        a = (f32)a * (d - 4.0f) * 0.25f;
    }
    *(s32 *)(s + 4) = (a << 24) | (*(s32 *)(s + 4) & 0xFFFFFF);
    __asm__ __volatile__(
        "lqc2 vf1, 16(%0)\n\t"
        "lqc2 vf2, 0(%1)\n\t"
        "vadd.xyz vf1, vf1, vf2\n\t"
        "sqc2 vf1, 16(%0)"
        : : "r"(s), "r"(q) : "memory");
    *(f32 *)(q + 8) -= t.v[*(s16 *)(q + 26)];
    pos = *(V4 *)(s + 16);
    if (!(*(f32 *)(s + 24) < *(f32 *)(q + 12))) {
        goto inc;
    }
    if (*(s16 *)(q + 26) == 1) {
        c1 = func_00444338(0x7F000000, 0x7F182030, func_004408C0(0.25f, 1.0f));
        c2 = func_00444338(0, 0x5F5F5F, func_004408C0(0.5f, 1.0f));
        *(f32 *)(q + 8) = 0.0f;
        r = func_004408C0(200000.0f, 300000.0f);
        n = func_00440878(90, 150);
        func_00462578(s + 16, q, c1, c2, r, n, 3);
    }
kill:
    func_0045E580(s);
    return;
inc:
    s[8]++;
}
/* localdecomp:end func_00462718 */
