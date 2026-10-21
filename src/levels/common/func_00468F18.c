#include "common.h"

/* localdecomp:start func_00468F18 */
typedef int Q_468F18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_468F18;
typedef struct {
    u8 pad0[4];
    s32 col;
    u8 pad1[2];
    s16 h;
    u8 pad2[4];
    V_468F18 pos;
    struct { f32 vx, vy, vz; f32 pad; f32 px, py, pz; s32 mode; } s;
} O_468F18;
extern V_468F18 D_001A4C60;
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(O_468F18 *);
extern s32 func_0040D020(f32, s32, s32);
void func_00468F18(O_468F18 *o) {
    V_468F18 t, u;
    struct { f32 vx, vy, vz; f32 pad; f32 px, py, pz; s32 mode; } *p = &o->s;
    t.w = 0.0f;
    t.x = p->vx;
    t.y = p->vy;
    t.z = p->vz;
    if (p->mode == 1) {
        Q_468F18 q1, q2, q3;
        u = D_001A4C60;
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(t));
        o->pos.x = u.x + p->px;
        o->pos.y = u.y + p->py;
        o->pos.z = u.z + p->pz;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(o->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(q3));
        p->px = o->pos.x - u.x;
        p->py = o->pos.y - u.y;
        p->pz = o->pos.z - u.z;
    } else {
        Q_468F18 q1, q2, q3;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(q3));
    }
    if (o->pos.x < 2.0f || o->pos.x > 1021.0f || o->pos.y < 2.0f || o->pos.y > 1021.0f
        || o->pos.z < 2.0f || o->pos.z > 1021.0f || func_0040BAC0(&o->h) != 0) {
        func_0045E580(o);
    } else if (o->h < 300) {
        s32 c = o->col;
        o->col = func_0040D020((f32)(o->h - 1) / (f32)o->h, c & 0xFFFFFF, c);
    }
}
/* localdecomp:end func_00468F18 */
