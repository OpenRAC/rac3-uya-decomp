#include "common.h"
typedef int Q_00462C38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00462C38;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[4];
    s32 w12;
    V4_00462C38 v16;
    V4_00462C38 v32;
    V4_00462C38 v48;
} O_00462C38;
extern void func_004C6EC8(void *, void *);
extern void func_0045E580(void *);
/* localdecomp:start func_00462C38 */
void func_00462C38(O_00462C38 *o) {
    s32 v;
    V4_00462C38 *a = &o->v16;
    V4_00462C38 *b = &o->v32;
    V4_00462C38 *c = &o->v48;
    Q_00462C38 x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v48));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v16));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v16) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v48));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v32));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v32) : "j"(x));
    func_004C6EC8(a, a);
    func_004C6EC8(b, b);
    v = o->w4 - ((s32)c->w << 24);
    o->w4 = v;
    o->w12 = v;
    if (v < 0) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00462C38 */
