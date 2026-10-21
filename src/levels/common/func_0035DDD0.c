#include "common.h"

/* localdecomp:start func_0035DDD0 */
typedef int Q_35DDD0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35DDD0;
extern V4_35DDD0 D_001E2A40;
extern f32 func_0040C490(f32, f32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void func_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
static __inline__ void vsubA_35DDD0(V4_35DDD0 *d, V4_35DDD0 *a, V4_35DDD0 *b) {
    Q_35DDD0 x, y, z;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(z));
}
void func_0035DDD0(V4_35DDD0 *obj) {
    V4_35DDD0 v;
    V4_35DDD0 vel;
    V4_35DDD0 pos;
    f32 ang;
    f32 e;
    f32 r;
    f32 d;
    s32 k;
    s32 n;
    f32 big;

    vsubA_35DDD0(&v, &D_001E2A40, obj);
    ang = func_0040C490(v.x, v.y);
    for (n = 19; n >= 0; n--) {
        e = func_004408C0(0.5f, 1.0f);
        k = (s32)func_00440918(1.0f, 2.0f);
        func_004408C0(0.05f, 0.2f);
        big = 210000.0f;
        r = func_004408C0(0.0f, 1.3962634f);
        d = func_0040CEC8(ang, func_00440918(0.0f, 1.3962634f));
        func_00440CF8(&vel, e * 0.016666668f, d, r);
        pos.x = obj->x + func_00440918(0.0f, 0.1f);
        pos.y = obj->y + func_00440918(0.0f, 0.1f);
        pos.z = obj->z + func_00440918(0.0f, 0.1f);
        func_00466F98(&pos, &vel, 30, 127, 0x7F7F7F, k, func_004408C0(0.05f, 0.2f) * big, 500.0f, 1.0f, 0.0f, 1.0f);
    }
}
/* localdecomp:end func_0035DDD0 */
