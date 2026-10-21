#include "common.h"

/* localdecomp:start func_00463FE8 */
typedef int Q_463FE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_463FE8;
typedef struct {
    u8 pad0[4];
    u32 w4;
    u8 pad8[8];
    V4_463FE8 v10;
    V4_463FE8 v20;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
} O_463FE8;
typedef struct {
    u8 pad[0x10];
    s32 m0;
    s32 m1;
    s32 m2;
} M_463FE8;
extern s32 func_0040BA90(void *);
extern void func_0045E580(void *);
void func_00463FE8(O_463FE8 *o) {
    Q_463FE8 a, b;
    M_463FE8 *m;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->v20));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(a));
    m = (M_463FE8 *)&o->v20;
    o->w4 = (o->w4 & 0xFFFFFF) + ((u32)(m->m2 * m->m0 / m->m1) << 24);
    if (func_0040BA90(&o->a0)) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00463FE8 */
