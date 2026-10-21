#include "common.h"

/* localdecomp:start func_00467620 */
typedef int Q_467620 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_467620;
typedef struct {
    u8 pad0[4];
    u32 w4;
    u8 b8;
    u8 pad9;
    u16 hA;
    f32 fC;
    V4_467620 v10;
    V4_467620 v20;
} O_467620;
typedef struct {
    u8 pad0[16];
    f32 f10;
    f32 f14;
    f32 *p18;
} T_467620;
extern void func_0045E580(O_467620 *);
extern f32 fabsf(f32);
void func_00467620(O_467620 *o) {
    Q_467620 a, b, r;
    T_467620 *t = (T_467620 *)((u8 *)o + 0x20);
    f32 *p;
    s32 h;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->v20));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r));
    o->fC = o->fC + 5880.0f;
    t->f14 = t->f14 * 0.98f;
    t->f10 = t->f10 + t->f14;
    o->b8 = (s32)t->f10;
    p = t->p18;
    if (p != 0) {
        if (fabsf(o->v10.z - *p) < 0.2f) {
            o->v10.z = *p + 0.02f;
        }
    }
    h = o->hA - 1;
    o->hA = h;
    if ((h << 16) == 0) {
        o->w4 = o->w4 + 0xFF000000;
        o->hA = 1;
    }
    if ((o->w4 & 0xFF000000) == 0) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00467620 */
