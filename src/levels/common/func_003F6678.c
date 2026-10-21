#include "common.h"

/* localdecomp:start func_003F6678 */
typedef int Q_3F6678 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3F6678;
typedef struct {
    u8 pad0[32];
    V4_3F6678 pos;
    V4_3F6678 *pts;
    u8 pad1[32];
    s32 i54;
    u8 count;
    u8 idx[3];
    u8 n;
} S_3F6678;
typedef struct {
    V4_3F6678 v0;
    V4_3F6678 v10;
    V4_3F6678 v20;
} G_3F6678;
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_004C1E50(s32);
extern void *func_003F9498(void *, f32, s32, s32);
extern s32 func_003FC040(void *, void *, void *, s32);
extern s32 D_001E10E0[];
extern s32 D_001E10E8;
extern s32 D_001E10F0;
extern s32 D_001E10F4;
extern s32 D_001DFC88;
extern s32 D_001D545C;
extern G_3F6678 D_001EAAA0;
s32 func_003F6678(u8 *obj) {
    V4_3F6678 a;
    V4_3F6678 b;
    V4_3F6678 c;
    V4_3F6678 d;
    S_3F6678 *s = *(S_3F6678 **)(obj + 104);
    void *r;
    s32 i, j, found, mask;
    Q_3F6678 x, y, z;

    func_0040C2D0(&a, &s->pos, obj + 192);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3F6678 *)(obj + 16)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(z));
    D_001DFC88 = D_001E10E0[D_001E10F4] + D_001E10F0 - 0x8000;
    if (D_001DFC88 < D_001E10E8) {
        func_004C1E50(1);
        D_001DFC88 = D_001E10E0[1 - D_001E10F4] + D_001E10F0 - 0x8000;
    }
    switch (D_001D545C) {
    case 42:
    case 45:
        mask = 0xB20;
        break;
    case 41:
        mask = 0xD20;
        break;
    default:
        mask = 0x20;
        break;
    }
    r = func_003F9498(&a, *(f32 *)((u8 *)s + 44), mask | 0x42, s->i54);
    if (r != 0) {
        for (i = 0; i < s->count; i++) {
            found = 0;
            for (j = 0; j < s->n; j++) {
                if (s->idx[j] == i) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                Q_3F6678 p, q, t;
                func_0040C2D0(&b, &s->pts[i], obj + 192);
                __asm__("lqc2 %0, %1" : "=j"(p) : "m"(b));
                __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_3F6678 *)(obj + 16)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(p), "j"(q));
                __asm__("sqc2 %1, %0" : "=m"(b) : "j"(t));
                if (func_003FC040(&a, &b, r, 0) != 0) {
                    goto found;
                }
            }
        }
        return -1;
    found:
        {
            Q_3F6678 e, f, g, h, k, l;
            f32 dot;
            __asm__("lqc2 %0, %1" : "=j"(e) : "m"(b));
            __asm__("lqc2 %0, %1" : "=j"(f) : "m"(D_001EAAA0.v0));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(g) : "j"(e), "j"(f));
            __asm__("sqc2 %1, %0" : "=m"(c) : "j"(g));
            func_0040C0F0(&D_001EAAA0.v20, &D_001EAAA0.v20, 1.0f);
            dot = func_0040BEF8(&c, &D_001EAAA0.v20);
            func_0040C0F0(&d, &D_001EAAA0.v20, -dot);
            __asm__("lqc2 %0, %1" : "=j"(h) : "m"(*(V4_3F6678 *)(obj + 16)));
            __asm__("lqc2 %0, %1" : "=j"(k) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(l) : "j"(h), "j"(k));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_3F6678 *)(obj + 16)) : "j"(l));
            return i;
        }
    } else {
        s->n = 0;
    }
    return -1;
}
/* localdecomp:end func_003F6678 */
