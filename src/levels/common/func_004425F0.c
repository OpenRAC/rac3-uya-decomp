#include "common.h"

typedef int Q_4425F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4425F0;
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    s32 w1C;
    V_4425F0 v20;
    V_4425F0 v30;
    V_4425F0 v40;
} G_4425F0;

extern G_4425F0 D_001EAA80;
extern V_4425F0 D_001EAAA0;
extern f32 func_00443298(V_4425F0 *);
extern void func_0040C0F0(V_4425F0 *, V_4425F0 *, f32);
extern s32 func_003F8448(V_4425F0 *, V_4425F0 *, s32, s32, s32);
extern f32 func_0040BF68(V_4425F0 *);
extern f32 func_0040C490(f32, f32);
extern void func_0012FE98(V_4425F0 *, V_4425F0 *);
extern void func_0040BE90(V_4425F0 *, V_4425F0 *, f32);
extern s32 func_003F9498(V_4425F0 *, f32, s32, s32);
extern f32 func_0040BFE8(V_4425F0 *, V_4425F0 *);

/* localdecomp:start func_004425F0 */
s32 func_004425F0(s32 id, V_4425F0 *from, V_4425F0 *to, s32 flags, f32 height, f32 radius, f32 step, f32 slope) {
    V_4425F0 diff, dir, a, b, up, tmp;
    Q_4425F0 x, y;
    s32 ok = 1;
    f32 h, z;
    s32 i;
    s32 mode = flags & 2;

    to->z += height;
    h = func_00443298(to);
    to->z -= height;
    z = from->z;
    if (fabsf(h - z) > step) {
        if ((((flags ^ 1) & 1) && h < z) || z < h) {
            *to = *from;
            ok = 0;
        }
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*from));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*to));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(diff) : "j"(y));
    func_0040C0F0(&dir, &diff, radius * 1.2f);
    *(Q_4425F0 *)&up = 0;
    up.z = height;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*from));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(up));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(dir));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(y));
    if (ok != 0 && func_003F8448(&a, &b, mode | 0x24, id, 0) != 0) {
        G_4425F0 *g = &D_001EAA80;
        if (g->w1C > 0) {
            if (slope <= func_0040C490(g->v40.z, func_0040BF68(&g->v40))) {
                f32 d;
                g->v40.z = 0.0f;
                func_0012FE98(&g->v40, &g->v40);
                d = -diff.x * g->v40.x - diff.y * g->v40.y;
                if (0.0f < d) {
                    ok = 0;
                    func_0040BE90(&g->v40, &g->v40, d);
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(g->v40));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(diff));
                    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
                    __asm__("sqc2 %1, %0" : "=m"(diff) : "j"(y));
                }
            }
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*from));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(diff));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*to) : "j"(y));
        }
    }
    if (!(flags & 2)) {
        f32 off = height + radius;
        i = 0;
        do {
            tmp = *to;
            tmp.z += off;
            if (func_003F9498(&tmp, radius, 36, id) == 0) break;
            {
                G_4425F0 *g;
                f32 t = func_0040BFE8(to, &D_001EAAA0);
                g = (G_4425F0 *)((u8 *)&D_001EAAA0 - 0x20);
                t = func_0040C490(t, g->v20.z - to->z);
                if (g->w18 != 0 || slope < t) {
                    *to = g->v30;
                    ok = 0;
                    to->z -= off;
                }
            }
            i++;
        } while (i < 6);
    }
    to->z += height;
    h = func_00443298(to);
    to->z -= height;
    z = from->z;
    if (fabsf(h - z) > step) {
        if ((((flags ^ 1) & 1) && h < z) || z < h) {
            *to = *from;
            ok = 0;
        }
    }
    from->x = to->x;
    from->y = to->y;
    return ok;
}
/* localdecomp:end func_004425F0 */
