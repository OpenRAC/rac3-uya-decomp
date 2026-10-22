#include "common.h"

/* localdecomp:start func_0062F9A8 */
typedef int Q_62F9A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_62F9A8;
extern f32 func_0058F8B8(f32);
extern f32 func_0058F8D0(f32);
extern void func_0058F7B8(V4_62F9A8 *, V4_62F9A8 *, void *);

void func_0062F9A8(u8 *o, V4_62F9A8 *out, s32 add, f32 r, f32 ang, f32 z) {
    Q_62F9A8 a, b, s;

    out->x = func_0058F8B8(ang) * r;
    out->y = func_0058F8D0(ang) * r;
    out->z = z;
    func_0058F7B8(out, out, o + 0x20);
    if (add != 0) {
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_62F9A8 *)(o + 0xA0)));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*out));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(s) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(s));
    }
}
/* localdecomp:end func_0062F9A8 */
