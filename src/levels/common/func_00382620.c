#include "common.h"

/* localdecomp:start func_00382620 */
typedef int Q_00382620 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00382620;
extern V4_00382620 D_001E2A40;
extern f32 func_0040C490(f32, f32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
void func_00382620(V4_00382620 *p) {
    V4_00382620 d;
    V4_00382620 v10;
    V4_00382620 v20;
    Q_00382620 x, y, r;
    f32 ang;
    f32 f21;
    f32 f20;
    f32 t;
    f32 w;
    s32 n;
    s32 i;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*p));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    ang = func_0040C490(d.x, d.y);
    for (i = 19; i >= 0; i--) {
        f21 = func_004408C0(0.5f, 1.0f);
        n = (s32)func_00440918(1.0f, 2.0f);
        func_004408C0(0.1f, 0.3f);
        w = 210000.0f;
        f20 = func_004408C0(0.0f, 1.3962634f);
        t = func_0040CEC8(ang, func_00440918(0.0f, 1.3962634f));
        func_00440CF8(&v10, f21 * 0.016666668f, t, f20);
        v20.x = p->x + func_00440918(0.0f, 0.2f);
        v20.y = p->y + func_00440918(0.0f, 0.2f);
        v20.z = p->z + func_00440918(0.0f, 0.2f);
        t = func_004408C0(0.05f, 0.2f);
        func_00466F98(&v20, &v10, 0x1E, 0x7F, 0x7F7F7F, n, w * t, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_00382620 */
