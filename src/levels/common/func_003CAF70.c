#include "common.h"

typedef int Q_3CAF70 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3CAF70;
extern s32 D_001DFBC0;
extern void func_0040BE90(void *a, void *b, f32 c);
extern void func_00437698(u8 *a, s32 b, void *c);
extern void func_003CAD78(u8 *a, s32 b, void *c, s32 d);

/* localdecomp:start func_003CAF70 */
void func_003CAF70(u8 *a0, s32 a1) {
    V_3CAF70 v[2];
    Q_3CAF70 x, y;
    s32 i;
    if (((*(s16 *)(a0 + 0xB2) + D_001DFBC0) & 1) == 0) {
        func_0040BE90(&v[1], a0 + 0xC0, -0.1f);
        v[1].z = v[1].z - 0.15f;
        for (i = 0; i < 2; i++) {
            func_00437698(a0, i + 1, &v[0]);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[0]));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v[1]));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v[0]) : "j"(x));
            func_003CAD78(a0, a1, &v[0], 1);
        }
    }
}
/* localdecomp:end func_003CAF70 */
