#include "common.h"

/* localdecomp:start func_00460D98 */
typedef int Q_00460D98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00460D98;
typedef struct {
    V4_00460D98 v0;
    s32 w10;
    s32 w14;
    s32 w18;
    f32 f1C;
} Q2_00460D98;
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
    V4_00460D98 v10;
    Q2_00460D98 q;
} Node_00460D98;
extern u8 *D_00221138[];
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern u32 func_0040D020(s32, s32, f32);
void func_00460D98(Node_00460D98 *o) {
    Q2_00460D98 *q = &o->q;
    Q_00460D98 a, b;
    u32 v;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(q->v0));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(a) : "j"(b));
    __asm__(".set noreorder; sqc2 %1, %0; .set reorder" : "=m"(o->v10) : "j"(a));
    if (func_0040BAC0(&o->hA) != 0) {
        func_0045E580(o);
    } else {
        o->fC = o->fC + q->f1C;
        v = func_0040D020(q->w14, q->w10, (f32)o->hA / (f32)q->w18);
        o->w4 = v;
        if (o->hA < 6) {
            o->w4 = (v & 0xFFFFFF) | (((o->hA * (s32)(v >> 24)) / 6) << 24);
        }
        o->b2 = D_00221138[0][(q->w18 - o->hA) * 10 / q->w18];
    }
}
/* localdecomp:end func_00460D98 */
