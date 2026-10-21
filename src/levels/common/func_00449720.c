#include "common.h"

/* localdecomp:start func_00449720 */
typedef int Q_449720 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_449720;
typedef struct {
    u8 pad[0x10];
    V4_449720 vec;
    u8 pad2[0x1C];
    s32 flags;
} Q1_449720;
typedef struct {
    u8 pad[0x10];
    V4_449720 vec;
    u8 pad2[2];
    u8 b22;
} B_449720;
typedef struct {
    u8 pad[0x22];
    u8 b22;
} A_449720;
extern A_449720 *D_001A71A0[];
extern Q1_449720 *func_00449388(void *);
extern void func_0040C658(void *, void *);
extern void func_0040C8A0(void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040C9B0(void *, void *, void *);
extern void func_00447748(void *, void *);
extern void func_004498A0(void *, void *, void *, void *, void *, void *);
extern void func_00448B80(void *, f32);
s32 func_00449720(A_449720 *a, B_449720 *b, void *c, void *d, V4_449720 *e, void *f) {
    Q1_449720 *q;
    V4_449720 v0[4], v1[4], v2;
    Q_449720 x, y;
    q = func_00449388(b);
    if (q == 0) {
        return 0;
    }
    if (q->flags & 0x40) {
        func_0040C658(v0, (u8 *)b + 0xF0);
    } else {
        func_0040C8A0(v0, (u8 *)b + 0xC0);
    }
    func_0040C2D0(e, c, v0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b->vec));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*e));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*e) : "j"(x));
    func_0040C658(v1, d);
    func_0040C9B0(v1, v0, v1);
    func_00447748(v1, f);
    if (q->flags & 4) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q->vec));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*e));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*e) : "j"(x));
        func_004498A0(a, b, e, f, c, d);
        return 1;
    }
    if (a == D_001A71A0[0]) {
        return 1;
    }
    if (a->b22 < b->b22) {
        v2 = q->vec;
        func_00448B80(&v2, 1.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*e));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v2));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*e) : "j"(x));
    }
    return 1;
}
/* localdecomp:end func_00449720 */
