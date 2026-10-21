#include "common.h"

/* localdecomp:start func_0046C260 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46C260;
typedef int Q_46C260 __attribute__((mode(TI)));
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
    V_46C260 v10;
    V_46C260 v20;
} S_46C260;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s16 h18;
    u8 b1A;
    u8 pad1B;
    f32 f1C;
} E_46C260;
extern s32 func_00440848(s32);
extern void func_00467288(void *, s32, s32, f32, f32);
extern void func_00465410(void *, void *, s32, s32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
void func_0046C260(S_46C260 *o) {
    E_46C260 *e = (E_46C260 *)&o->v20;
    V_46C260 *p = &o->v10;
    Q_46C260 x, y;
    e->f10 += 0.0075f;
    e->f8 -= e->fC;
    o->fC = e->f14 * e->f10 * 210000.0f;
    o->b8 += e->b1A;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v20));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
    if (o->v10.z <= e->f1C) {
        if (func_00440848(6) == 1) {
            func_00467288(p, 0, -1, 0.4f, 31500.002f);
        }
    }
    if (func_00440848(6) == 1 && e->h18 >= 50) {
        func_00465410(&o->v10, e, 1, 20);
    }
    e->h18++;
    if (func_0040BAC0(&o->hA)) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_0046C260 */
