#include "common.h"

/* localdecomp:start func_0034CF60 */
typedef int Q_34CF60 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_34CF60;
typedef struct {
    V4_34CF60 p0;
    V4_34CF60 p16;
    V4_34CF60 p32;
    V4_34CF60 p48;
    u8 pad64[104];
    s32 i168;
} S_34CF60;
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern void func_0034CE48(void *, void *, void *, void *, void *, f32);
extern void func_0034D168(void *, s32, void *, s32);

void func_0034CF60(void *a0, S_34CF60 *y) {
    V4_34CF60 out[25];
    V4_34CF60 A, B, C, D;
    s32 i;

    for (i = 0; i < 24; i++) {
        Q_34CF60 a, b;
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
        func_0034CE48(&out[i], &y->p32, &y->p48, &A, &B, (f32)i / 23.0f);
        C.w = 0.0f;
        C.x = func_004408C0(-1.0f, 1.0f);
        C.y = func_004408C0(-1.0f, 1.0f);
        C.z = func_004408C0(-1.0f, 1.0f);
        func_0040C0F0(&C, &C, 0.075f);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(out[i]));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(C));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(a) : "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(out[i]) : "j"(a));
    }
    if (y->i168 >= 10) {
        func_0034D168(a0, func_00440878(64, 128), out, 25);
    } else {
        func_0034D168(a0, func_00440878(0, 64), out, 25);
    }
}
/* localdecomp:end func_0034CF60 */
