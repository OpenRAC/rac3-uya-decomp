#include "common.h"

/* localdecomp:start func_004EB490 */
typedef int Q_4EB490 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4EB490;
typedef struct {
    u8 pad0[240];
    V_4EB490 v240;
    u8 pad256[24];
    f32 f280;
    u8 pad284[308];
    V_4EB490 v592;
    u8 pad608[71];
    u8 f679;
    u8 pad680[148];
    f32 f828;
    u8 pad832[46];
    s16 f878;
} G_4EB490;
extern G_4EB490 D_001A4BE0;
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);
extern void func_0012FE98(void *, void *);
extern void func_0040BE90(void *, void *, f32);
void func_004EB490(void) {
    V_4EB490 v;
    Q_4EB490 a, b, c;
    f32 d;
    if (D_001A4BE0.f878 != 0 && D_001A4BE0.f828 < 0.15f && 0.0f < D_001A4BE0.f280 && D_001A4BE0.f679 != 0 &&
        0.0f < D_001A4BE0.v592.z) {
        if (0.87266463f <= func_0040C490(D_001A4BE0.v592.z, func_0040BF68(&D_001A4BE0.v592))) {
            v = D_001A4BE0.v592;
            v.z = 0.0f;
            func_0012FE98(&v, &v);
            d = -D_001A4BE0.v240.x * v.x - D_001A4BE0.v240.y * v.y;
            if (0.0f < d) {
                func_0040BE90(&v, &v, d);
                __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001A4BE0.v240));
                __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
                __asm__("sqc2 %1, %0" : "=m"(D_001A4BE0.v240) : "j"(c));
                D_001A4BE0.v240.z = D_001A4BE0.v240.z - 0.030000001f;
            }
        }
    }
}
/* localdecomp:end func_004EB490 */
