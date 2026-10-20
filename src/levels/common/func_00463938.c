#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *D_0022117C[];
extern u8 *func_0045E438(s32);
extern s32 func_00445B88(f32, f32, f32, f32);
extern f32 func_004408C0(f32, f32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

void func_00463938(s128 *a0, s128 *a1, s32 a2, f32 f12, f32 f13) {
    u8 *p = func_0045E438(25);
    u8 *q;
    if (p == 0) {
        return;
    }
    *(s128 *)(p + 16) = *a0;
    q = p + 32;
    if (a2 == 0) {
        S32(p, 4) = func_00445B88(1.0f, 1.0f, 1.0f, 0.6f);
        F32(q, 16) = 1.0f;
        F32(q, 20) = 1.0f;
        F32(q, 24) = 1.0f;
    } else {
        S32(p, 4) = func_00445B88(1.0f, 1.0f, 1.0f, 0.6f);
        F32(q, 16) = -1.0f;
        F32(q, 20) = -1.0f;
        F32(q, 24) = -1.0f;
    }
    U8(p, 9) = 68;
    U8(p, 3) = 72;
    U8(p, 1) = 0;
    if (f12 < 0.0f) {
        F32(p, 12) = func_004408C0(5000.0f, 30000.0f);
    } else {
        F32(p, 12) = f12;
    }
    U8(p, 8) = 0;
    U8(p, 2) = *D_0022117C[0];
    F32(q, 28) = 0.6f;
    S16(p, 10) = 80;
    *(s128 *)q = *a1;
    F32(q, 12) = f13;
}
