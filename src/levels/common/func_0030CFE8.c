#include "common.h"

/* localdecomp:start func_0030CFE8 */
typedef int Q_30CFE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30CFE8;
typedef struct {
    u8 pad[0x18];
    f32 f18;
} X_30CFE8;
typedef struct {
    u8 pad[0x10];
    V4_30CFE8 vec;
    u8 pad2[0x48];
    X_30CFE8 *ptr;
} O_30CFE8;
typedef struct {
    u8 pad[0x10];
    O_30CFE8 *owner;
    f32 f14;
    s32 i18;
    s32 i1C;
    f32 f20;
    f32 f24;
    u8 pad2[8];
} P_30CFE8;
extern P_30CFE8 *D_001E17A0;
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_0040C3C8(f32);
extern void func_0030D990(void *, void *, s32, s32, s32, s32, f32, f32, f32);
void func_0030CFE8(O_30CFE8 *o) {
    s32 i;
    P_30CFE8 *p;
    V4_30CFE8 v;
    s32 r;
    f32 c;
    Q_30CFE8 a, b, d;
    for (i = 0; i < 64; i++) {
        p = (P_30CFE8 *)(i * 0x30 + (s32)D_001E17A0);
        if (p->owner != o) {
            continue;
        }
        p->f24 = 6.2831855f - (f32)p->i18 * 6.2831855f / (f32)(p->i1C - 1);
        func_0040C0F0(&v, p, p->f14);
        r = func_00440878(0x30, 0x50);
        c = func_0040C3C8(p->f24 - 3.1415927f) + 1.0f;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->vec));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(d));
        func_0030D990(&o->vec, &v, 0x800000, (s32)((f32)r * (c * 0.5f)), 0x2F, 2, o->ptr->f18 * 0.25f, 0.0f, p->f20);
    }
}
/* localdecomp:end func_0030CFE8 */
