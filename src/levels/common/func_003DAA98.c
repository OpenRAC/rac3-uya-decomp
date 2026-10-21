#include "common.h"

/* localdecomp:start func_003DAA98 */
typedef int Q_3DAA98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DAA98;
typedef struct {
    u8 pad0[16];
    V4_3DAA98 pos;
    u8 pad20[160];
    u8 f192[48];
    f32 f240;
    f32 f244;
    f32 f248;
} O_3DAA98;
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);
extern void func_00445558(void *, s32, f32, f32);
extern void func_0040C638(void *, void *);
extern f32 func_0040BE90(void *, void *, f32);
f32 func_003DAA98(O_3DAA98 *obj, u8 *o2, V4_3DAA98 v, f32 spd) {
    V4_3DAA98 d;
    Q_3DAA98 p, q, r;
    f32 ang;

    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(obj->pos));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(v));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    if (d.z < 3.0f) {
        ang = -1.5707964f;
    } else {
        ang = -func_0040C490(func_0040BF68(&d), d.z);
    }
    func_00445558(&obj->f244, 0, ang, spd);
    ang = func_0040C490(d.x, d.y);
    func_00445558(&obj->f248, 0, ang, spd);
    func_0040C638(obj->f192, &obj->f240);
    return func_0040BE90(o2, obj->f192, *(f32 *)(o2 + 32));
}
/* localdecomp:end func_003DAA98 */
