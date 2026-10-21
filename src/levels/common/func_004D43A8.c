#include "common.h"

/* localdecomp:start func_004D43A8 */
/* PROVISIONAL, VU0 j-constraint form. */
typedef int Q_3B8560 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B8560;
typedef struct { u8 p0[0xC]; u8 c; } I_3B8560;
typedef struct {
    u8 p0[0x10];
    V4_3B8560 v10;
    u8 p20[0x4];
    I_3B8560 *f24;
    u8 p28[0xA];
    s16 f32;
    u8 p34[0xC];
    u8 f40, f41, f42, f43;
    f32 f44;
    u8 p48[0x19];
    u8 f61, f62;
    u8 p63[0x5];
    u8 *f68;
    u8 p6C[0x3E];
    s16 fAA;
} O_3B8560;
typedef struct { u8 p0[0x38]; s32 f38; u8 p3C[0x8]; s16 n; u8 p46[0x15A]; O_3B8560 *slot[1]; } S_3B8560;
extern S_3B8560 D_001E6E00_003B8560;
extern void func_0040BE90(f32 *, void *, f32);
extern void func_00436350();
extern void func_00439610();
extern void func_004D4288(u8 *);
void func_004D43A8(void) {
    s32 i;
    for (i = 0; i < D_001E6E00_003B8560.n; i++) {
        V4_3B8560 a, b;
        Q_3B8560 x, y, r;
        O_3B8560 *o = D_001E6E00_003B8560.slot[i];
        s32 bits = D_001E6E00_003B8560.f38;
        s32 hi = bits >> 1;
        u8 *t = o->f68;
        s32 k;
        o->f44 = (f32)(bits & 1) * 0.5f;
        func_0040BE90(&a.x, t + hi * 16, 1.0f - o->f44);
        func_0040BE90(&b.x, t + (hi + 1) * 16, o->f44);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(Q_3B8560 *)&a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(Q_3B8560 *)&b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r));
        o->f42 = o->f24->c - 1;
        o->f43 = o->f24->c - 1;
        o->f40 = hi;
        o->f41 = hi + 1;
        func_00436350(o);
        o->f62 = 0xFF;
        o->f61 = 0xFF;
        o->f32 = 0x1FF;
        func_00439610(o);
        o->f42 = o->f24->c - 1;
        o->f43 = o->f24->c - 1;
        k = o->fAA;
        if (k == 10 || k == 0x19C9 || k == 0x1159 || k == 0x57 || k == 0x259 || k == 0x1F6B) {
            func_004D4288((u8 *)o);
        }
    }
}
/* localdecomp:end func_004D43A8 */
