#include "common.h"

/* localdecomp:start func_00470A38 */
typedef int Q_00470A38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00470A38;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s16 hC;
} Sub_00470A38;
typedef struct {
    u8 pad0[4];
    u32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    u32 wC;
    V4_00470A38 v10;
    V4_00470A38 v20;
    Sub_00470A38 s;
} Obj_00470A38;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_004C6EC8(void *, void *);
void func_00470A38(Obj_00470A38 *o) {
    V4_00470A38 d;
    Q_00470A38 x, y;
    Sub_00470A38 *s;
    V4_00470A38 *q;
    f32 r;
    s32 v;
    s = &o->s;
    if (func_0040BAC0(&o->hA) != 0) {
        func_0045E580(o);
        return;
    }
    q = &o->v20;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*q));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    d.w = 0.0f;
    func_0040C0F0(&d, &d, s->f0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*q) : "j"(x));
    func_004C6EC8(&o->v10, &o->v10);
    func_004C6EC8(q, q);
    r = (f32)o->hA / (f32)s->hC;
    o->v10.w = s->f4 * ((s->f8 - 1.0f) * r + 1.0f);
    if (o->hA < o->b8) {
        v = (s32)((f32)o->hA / (f32)o->b8 * 127.0f);
        o->w4 = (v << 24) | (o->w4 & 0xFFFFFF);
        o->wC = (v << 24) | (o->wC & 0xFFFFFF);
    }
}
/* localdecomp:end func_00470A38 */
