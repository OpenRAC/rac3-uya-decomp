#include "common.h"

/* localdecomp:start func_00318928 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_318928;
typedef int Q_318928 __attribute__((mode(TI)));
typedef struct { V_318928 v0; f32 f10[4]; f32 f20; f32 f24; f32 f28; f32 f2c; s32 f30; s32 f34; s32 f38; s32 f3c; s32 f40; s32 f44; s32 f48; s32 f4c; } S_318928;
extern S_318928 D_00272800[];
extern u8 D_1A4BE0[];
extern void func_00318C50(V_318928 *, f32, s32, s32, s32, s32, f32, f32);

void func_00318928(u8 *a0) {
    s32 i;
    u8 *g = D_1A4BE0;
    V_318928 v;
    for (i = 0; i < 64; i++) {
        S_318928 *e = &D_00272800[i];
        if (e->f44 == (s32)a0) {
            Q_318928 x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->v0));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_318928 *)(*(u8 **)(g + 0x25C0) + 0x10)));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
            func_00318C50(&v, e->f20, 0x7F7F7F, e->f34, 0x31, 2, e->f2c, 0.001f);
            func_00318C50(&v, e->f24, e->f38, e->f34 >> 1, 0x31, 2, e->f2c, 0.001f);
        }
    }
}
/* localdecomp:end func_00318928 */
