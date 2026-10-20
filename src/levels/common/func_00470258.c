#include "common.h"
typedef int s128_00470258 __attribute__((mode(TI)));
typedef struct {
    s128_00470258 v;
    s32 f10;
    s32 f14;
    s16 f18;
    u8 f1A;
} Sub_00470258;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00470258 f10;
    Sub_00470258 sub;
} Part_00470258;
extern u8 *D_0022117C[];
extern Part_00470258 *func_0045E438(s32);
extern u8 func_00440878(s32, s32);
void func_00470258(s128_00470258 *pos, s128_00470258 *v2, s32 a2, s32 a3, s16 t0, u8 t1, f32 f) {
    Part_00470258 *p;
    Sub_00470258 *q;
    p = func_0045E438(114);
    if (p != 0) {
        p->f10 = *pos;
        p->f9 = 68;
        p->f3 = 72;
        p->fC = f;
        p->f1 = 0;
        p->f8 = 0;
        p->f2 = *D_0022117C[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        p->f4 = a2;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        p->f8 = func_00440878(0, 255);
        q->v = *v2;
    }
}
