#include "common.h"

/* localdecomp:start func_0046C640 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46C640;
typedef int Q_46C640 __attribute__((mode(TI)));
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    V_46C640 v10;
} S_46C640;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14;
    u8 b15;
    s16 h16;
    f32 f18;
} E_46C640;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern void func_004C6EC8(void *);
void func_0046C640(S_46C640 *o) {
    E_46C640 *e;
    V_46C640 *p;
    V_46C640 t;
    Q_46C640 x, y;
    if (func_0040BAC0(&o->hA)) {
        func_0045E580(o);
        return;
    }
    e = (E_46C640 *)((u8 *)o + 0x20);
    p = &o->v10;
    t.w = 0.0f;
    e->f18 += (f32)e->h16 * 0.00061037f;
    o->w4 = (o->w4 & 0xFFFFFF) | ((s32)e->f18 << 24);
    t.x = ((f32 *)o)[8];
    t.z = e->f8;
    t.y = e->f4;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(y));
    e->f8 = e->f8 - e->fC;
    if (((f32 *)o)[7] != t.w) {
        if (((f32 *)o)[7] == 2.0f) {
            func_004C6EC8(p);
        }
        ((f32 *)o)[7] = 2.0f;
    }
    o->b8 += e->b15;
    o->fC += e->f10;
}
/* localdecomp:end func_0046C640 */
