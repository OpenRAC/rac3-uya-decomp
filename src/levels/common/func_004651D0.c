#include "common.h"

/* localdecomp:start func_004651D0 */
typedef int Q_4651D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4651D0;
typedef struct {
    f32 x, y, z;
    f32 f12, f16, f20, f24, f28;
} P_4651D0;
typedef struct {
    u8 pad0[4];
    u32 c;
    u8 pad8[2];
    s16 h10;
    f32 f12;
    V4_4651D0 pos;
    P_4651D0 p;
} O_4651D0;
extern f32 D_001E2A58[];
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_00440848(s32);
extern f32 func_0040BF68(void *);
extern void func_0040C140(void *, void *, f32);
extern f32 func_004450C0(void *, f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);

void func_004651D0(O_4651D0 *o) {
    P_4651D0 *p = &o->p;
    V4_4651D0 v;
    f32 f20, f21;
    Q_4651D0 x, y;

    if (func_0040BAC0(&o->h10)) {
        func_0045E580(o);
        return;
    }
    if (o->pos.z > p->f16) {
        p->z = 0;
        if (o->h10 > 12) o->h10 = 12;
    }
    if (p->f16 < o->pos.z + 0.8666667f) {
        if (func_00440848(20) == 0) {
            if (o->h10 > 12) o->h10 = 12;
        }
    }
    if (o->h10 < 14) {
        o->c = ((s32)(o->c >> 24) * o->h10 / 14 << 24) | (o->c & 0xffffff);
    }
    o->f12 = o->f12 + 840.00006f;
    if (p->f12 < o->f12) o->f12 = p->f12;
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    func_0040C140(&v, &v, func_0040BF68(&v) * 0.97f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(y));
    func_004450C0(&v.z, 0.021666666f, 0.0013888889f);
    p->x = v.x;
    p->y = v.y;
    p->z = v.z;
    p->f20 = func_0040CEC8(p->f20, p->f24);
    f20 = func_0040CEC8(D_001E2A58[0], 1.5707964f);
    f21 = func_0040C3E0(p->f20) * p->f28;
    v.x = func_0040C3C8(f20) * f21;
    v.y = func_0040C3E0(f20) * f21;
    v.z = 0;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(y));
}
/* localdecomp:end func_004651D0 */
