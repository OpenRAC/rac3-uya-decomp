#include "common.h"

/* localdecomp:start func_00375C70 */
typedef int Q_375C70 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_375C70;
typedef struct {
    u8 pad0[64];
    f32 f64;
    f32 f68;
    u8 pad72[40];
    f32 f112;
    f32 f116;
    f32 f120;
    f32 f124;
    u8 pad128[32];
    V_375C70 v160[24];
    V_375C70 v544[24];
    f32 f928[24];
} D_375C70;
typedef struct {
    u8 pad0[16];
    Q_375C70 pos;
    u8 pad32[72];
    D_375C70 *d;
} O_375C70;
extern f32 func_0040CEC8(f32, f32);
extern void func_003750E0(void *, s32, f32, f32, f32, f32);
extern void func_0040CCA0(void *, void *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_004084B0(f32, f32, f32, V_375C70 *, V_375C70 *, s32, s32, s32, s32, s32, s32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern void func_004082B0(void *, s32, s32, s32, f32, f32, f32);

void func_00375C70(O_375C70 *obj) {
    D_375C70 *d = obj->d;
    s32 i;
    V_375C70 a;
    V_375C70 b;

    d->f112 -= 0.04f;
    if (d->f112 <= 0.0f) {
        d->f112 = 0.0f;
    }
    d->f116 -= 0.025f;
    if (d->f116 <= 0.0f) {
        d->f116 = 0.0f;
    }
    d->f120 = func_0040CEC8(d->f120, 0.043633234f);
    d->f124 = func_0040CEC8(d->f120, 0.072722055f);
    func_003750E0(&obj->pos, 54, d->f112, 0.5f, d->f120, 0.5f);
    func_003750E0(&obj->pos, 54, d->f116, 0.5f, d->f124, 0.5f);
    func_003750E0(&obj->pos, 54, d->f68, 0.5f, -d->f120, 0.8f);
    func_003750E0(&obj->pos, 54, d->f68, 0.5f, d->f120, 0.8f);
    d->f68 -= 0.125f;
    if (d->f68 < 0.0f) {
        d->f68 = 0.0f;
    }
    for (i = 0; i < 24; i++) {
        Q_375C70 x, y, z;
        V_375C70 *q = &d->v160[i];
        f32 r = d->f928[i];
        V_375C70 *p = &d->v544[i];
        func_0040CCA0(p, p, q, r);
        func_0040C0F0(p, p, d->f68);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(z));
        b = *(V_375C70 *)&obj->pos;
        func_004084B0(0.08f, 3.0f, d->f64, &a, &b, 18, 1, 0x002020FF, 0x002020FF, 0x1FFF2020, 0x1FFF2020);
    }
    d->f64 -= func_004408C0(0.025f, 0.035f);
    if (d->f64 <= -8.0f) {
        d->f64 += 8.0f;
    }
    func_004082B0(&obj->pos, 57, 0x4FFFFFFF, 1, 0.25f, 0.0f, func_00440978());
    func_004082B0(&obj->pos, 11, 0x3FFF2040, 3, 0.3f, 0.01f, func_00440978());
    func_004082B0(&obj->pos, 57, 0x4FFFFFFF, 1, 0.27f, 0.0f, func_00440978());
    func_004082B0(&obj->pos, 11, 0x3FFF2040, 1, 0.35f, 0.01f, func_00440978());
}
/* localdecomp:end func_00375C70 */
