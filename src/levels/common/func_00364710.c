#include "common.h"

/* localdecomp:start func_00364710 */
typedef int Q_364710 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_364710;

extern s32 func_00462650(void);
extern void func_00451098(void *, s32, s32, s32);
extern void func_004681B0(void *, f32);
extern f32 func_0041C7D0(void *, void *);
extern void func_004513D8(void *, s32, s32);

s32 func_00364710(u8 *o) {
    u8 *v;
    s32 dir;
    f32 f;
    Q_364710 a, b, r;
    V4_364710 d;

    v = *(u8 **)(o + 0x68);
    if (func_00462650() != 0 && o[0x43] != 3) {
        func_00451098(o, 3, 0, 6);
    }
    func_004681B0(o, *(f32 *)(v + 0x36C));
    if (*(f32 *)(o + 0xF8) == *(f32 *)(v + 0x36C)) {
        dir = *(s32 *)(v + 0x308);
        if (dir == 2) {
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_364710 *)(v + 0x220)));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_364710 *)(v + 0x320)));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
            f = func_0041C7D0(&d, v + 0x330);
            dir = 1;
            if (f > 0.0f) {
                dir = -1;
            }
        }
        if (dir == 1) {
            func_004513D8(o, 0x13, -1);
        } else {
            func_004513D8(o, 0x16, -1);
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_00364710 */
