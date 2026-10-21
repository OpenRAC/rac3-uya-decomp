#include "common.h"

/* localdecomp:start func_0031B0A0 */
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} Vec4;

typedef struct {
    u8 b[8];
} Col8;

typedef struct {
    u8 pad[20];
    f32 *m;
    u8 pad2[8];
} Entry;

extern Entry D_00274600[];
extern u8 D_001DC860[];

extern void func_0044DF40(void *a, Vec4 *v, s32 c);
extern void func_0040BE90(Vec4 *a, Vec4 *b, f32 f);
extern f32 func_004408C0(f32 lo, f32 hi);
extern f32 func_00440978(void);
extern void func_00440CF8(Vec4 *v, f32 a, f32 b, f32 c);
extern s32 func_00440878(s32 lo, s32 hi);
extern u8 *func_004633E8(void *a, s32 b, f32 f0, f32 f1, Vec4 *v, f32 f2, f32 f3, u32 color, s32 e);
extern s32 func_0013D3E0(void);

void func_0031B0A0(void) {
    Vec4 base;
    Vec4 pos;
    Vec4 vel;
    s32 i;
    s32 j;
    Col8 cols;

    for (i = 0; i < 30; i++) {
        if (D_00274600[i].m != 0) {
            Entry *e = (Entry *)(i * 32 + (s32)D_00274600);
            func_0044DF40((u8 *)e->m + 16, &base, 1);
            func_0040BE90(&base, &base, e->m[3] * 0.0009765f * 0.8f);
            base.f[0] += e->m[0] * 0.0009765f;
            base.f[1] += e->m[1] * 0.0009765f;
            base.f[2] += e->m[2] * 0.0009765f;
            for (j = 0; j < 3; j++) {
                f32 r;
                f32 a;
                f32 b;
                s32 n;
                u8 *p;

                __asm__("sq $0,%0" : "=m"(vel.q));
                vel.f[2] = func_004408C0(0.0166666675f, 0.025000002f);
                r = e->m[3] * 0.0009765f * func_004408C0(0.5f, 0.75f);
                a = func_00440978();
                b = func_00440978();
                func_00440CF8(&pos, r, a, b);
                pos.f[0] += e->m[0] * 0.0009765f;
                pos.f[1] += e->m[1] * 0.0009765f;
                pos.f[2] += e->m[2] * 0.0009765f;
                n = func_00440878(1, 5);
                p = func_004633E8(&pos, n, 0.0f, 1.0f, &vel, 1.01f, func_004408C0(0.25f, 1.0f) * 210000.0f, 0x802040, 1);
                cols = *(Col8 *)&D_001DC860;
                if (p != 0) {
                    u8 *q = p + 32;
                    s32 r2 = func_0013D3E0() % 2;
                    p[3] = cols.b[r2 * 4];
                    *(s16 *)(p + 10) = 35;
                    p[9] = 68;
                    *(f32 *)(q + 28) = 5.0f;
                    *(s32 *)(q + 4) = 3;
                    q[10] = func_00440878(64, 128);
                    q[11] = p[10];
                }
            }
        }
    }
}
/* localdecomp:end func_0031B0A0 */
