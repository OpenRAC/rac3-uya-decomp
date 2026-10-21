#include "common.h"

extern void func_0040BE90(f32 *, void *, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_001EAAA0;
s32 func_003F8448(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);

typedef int Q_3BE860 __attribute__((mode(TI)));
extern V_3BE7F0 D_001A4C90;
extern void func_0044DF40_003BE860();
s32 func_004431B0(V_3BE7F0 *out, void *obj, s32 flags, s32 c, f32 scale) {
    V_3BE7F0 a, b, d;
    Q_3BE860 x, y;
    func_0044DF40_003BE860(obj, &d, 1);
    a = D_001A4C90;
    func_0040BE90((f32 *)&b, &d, scale);

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3BE7F0 *)obj));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    if (func_003F8448(&b, &a, flags | 2, c, 0)) {
        *out = D_001EAAA0;
        return 1;
    }
    *out = a;
    return 0;
}
