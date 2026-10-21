#include "common.h"

typedef int Q_3F3EA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3F3EA0;
typedef struct { f32 x, y, z; } V3_3F3EA0;
typedef struct {
    u8 pad0[100];
    f32 f64;
    f32 f68;
    f32 f6C;
    u8 pad70[0x89 - 0x70];
    u8 b89;
    s16 h8A;
} P_3F3EA0;
typedef struct {
    V_3F3EA0 v0;
    u8 pad10[0x50 - 0x10];
    P_3F3EA0 *p50;
    u8 pad54[0x240 - 0x54];
    s32 f240;
    u8 pad244[0x460 - 0x244];
} E_3F3EA0;

extern E_3F3EA0 D_001E2AC0[];
extern s32 D_001DF898[2];
extern V_3F3EA0 D_001EAAB0;
extern f32 func_0040BF38(V_3F3EA0 *);
extern void func_0040BED8(V_3F3EA0 *, V_3F3EA0 *, f32);
extern s32 func_003F9498(V_3F3EA0 *, s32, s32, f32);

/* localdecomp:start func_003F3EA0 */
void func_003F3EA0(s32 idx, V_3F3EA0 *pos, f32 speed)
{
    E_3F3EA0 *e;
    P_3F3EA0 *q;
    V_3F3EA0 d;
    V_3F3EA0 t;
    Q_3F3EA0 x, y, r;
    s32 n;
    s32 i;
    s32 j;
    V3_3F3EA0 *vp;

    e = &D_001E2AC0[idx];
    q = e->p50;
    vp = (V3_3F3EA0 *)&q->f64;
    t.x = vp->x;
    t.y = vp->y;
    t.z = vp->z;
    t.w = 0.0f;
    if (q->h8A != 0) {
        e->v0 = *pos;
        q->h8A = 0;
        return;
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    n = (s32)(func_0040BF38(&d) / (speed * 0.9f)) + 1;
    func_0040BED8(&d, &d, (f32)n);
    *pos = t;
    for (i = 0; i < n; i++) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(*pos) : "j"(y));
        for (j = 0; j < 6; j++) {
            if (func_003F9498(pos, D_001DF898[idx], e->f240, speed) == 0) {
                break;
            }
            *pos = D_001EAAB0;
            if (e->p50->b89 == 0) {
                e->p50->b89 = 1;
            }
        }
    }
    e->v0 = *pos;
}
/* localdecomp:end func_003F3EA0 */
