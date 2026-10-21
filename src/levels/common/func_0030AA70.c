#include "common.h"

/* localdecomp:start func_0030AA70 */
typedef int Q_30AA70 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30AA70;
typedef struct {
    V4_30AA70 p0;
    V4_30AA70 p16;
    V4_30AA70 p32;
    V4_30AA70 p48;
    u8 pad64[72];
    s32 i136;
} S_30AA70;
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern void func_0030A958(void *, void *, void *, void *, void *, f32);
extern void func_0030AC78(void *, s32, void *, s32);

void func_0030AA70(void *a0, S_30AA70 *y) {
    V4_30AA70 out[17];
    V4_30AA70 A, B, C, D;
    s32 i;

    for (i = 0; i < 16; i++) {
        Q_30AA70 a, b;
        A = y->p0;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(y->p32));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(y->p48), "m"(A), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(D) : "j"(b));
        B = y->p16;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(A));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(b) : "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(A) : "j"(b));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(B));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(b) : "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(B) : "j"(b));
        func_0030A958(&out[i], &y->p32, &y->p48, &A, &B, (f32)i / 15.0f);
        C.w = 0.0f;
        C.x = func_004408C0(-0.5f, 0.5f);
        C.y = func_004408C0(-0.5f, 0.5f);
        C.z = func_004408C0(-0.5f, 0.5f);
        func_0040C0F0(&C, &C, 0.075f);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(out[i]));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(C));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(a) : "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(out[i]) : "j"(a));
    }
    if (y->i136 >= 10) {
        func_0030AC78(a0, func_00440878(64, 128), out, 17);
    } else {
        func_0030AC78(a0, func_00440878(0, 64), out, 17);
    }
}
/* localdecomp:end func_0030AA70 */
