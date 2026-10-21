#include "common.h"

/* localdecomp:start func_0031CDB8 */
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} Vec4;

extern u8 D_002AE940[];

extern s32 func_00440848(s32 n);
extern f32 func_004408C0(f32 lo, f32 hi);
extern s32 func_00440878(s32 lo, s32 hi);
extern void func_00440A88(Vec4 *v, f32 a, f32 b);
extern u8 *func_004633E8(void *a, s32 b, Vec4 *v, f32 f0, f32 f1, f32 f2, f32 f3, u32 color, s32 e);
extern void func_0040C0F0(void *a, void *b, f32 f);
extern void func_00300650(void *a, void *b, s32 c, s32 d);

void func_0031CDB8(void *unused, void *a1, void *a2) {
    Vec4 v;
    s32 i;

    for (i = 19; i >= 0; i--) {
        f32 r;
        s32 c;
        u8 *p;

        func_00440848(2);
        func_00440848(2);
        r = func_004408C0(70000.0f, 150000.0f);
        c = func_00440878(10, 127);
        c = (0x7F << 24) | (c << 16) | (c << 8) | c;
        func_00440A88(&v, 1.66666687e-05f, 0.00666666729f);
        p = func_004633E8(a1, 0, &v, 0.3f, 1.0f, 1.01f, r, c, 1);
        if (p != 0) {
            u8 *q = p + 32;
            *(s16 *)(p + 10) = 120;
            *(s32 *)(q + 4) = 2;
            q[10] = 127;
            q[11] = p[10];
        }
    }
    func_0040C0F0(D_002AE940, a2, 1.5f);
    func_00300650(D_002AE940, a1, 0, 0);
}
/* localdecomp:end func_0031CDB8 */
