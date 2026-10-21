#include "common.h"

/* localdecomp:start func_00468600 */
typedef int Q_468600 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_468600;
typedef struct {
    u8 pad0[4];
    u32 color;
    u8 b8;
    u8 pad9;
    s16 life;
    f32 fC;
    V_468600 pos;
    V_468600 vel;
} O_468600;
typedef struct {
    V_468600 v;
    f32 f10;
    f32 f14;
} P_468600;
extern void func_0045E580(void *);
void func_00468600(O_468600 *o) {
    Q_468600 x, y;
    s32 h;
    P_468600 *p = (P_468600 *)&o->vel;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->vel));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(x));
    o->fC += 5880.0f;
    p->f14 *= 0.98f;
    p->f10 += p->f14;
    o->b8 = (s32)p->f10;
    o->life--;
    if (o->life <= 0) {
        func_0045E580(o);
    }
    h = o->life;
    if (h > 0x40) {
        o->color = ((0x80 - h) << 24) | 0x808080;
    } else {
        o->color = (h << 24) | 0x808080;
    }
}
/* localdecomp:end func_00468600 */
