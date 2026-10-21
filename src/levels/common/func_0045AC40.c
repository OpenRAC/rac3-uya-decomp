#include "common.h"

typedef int Q_45AC40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_45AC40;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    u8 pad1c[4];
    Q_45AC40 f20;
    Q_45AC40 f30;
} S_45AC40;
extern S_45AC40 D_001EAA80;
extern void func_0040C2D0(void *a, void *b, void *c);
extern s32 func_003F9498(void *a, s32 b, void *c, f32 d);

/* localdecomp:start func_0045AC40 */
s32 func_0045AC40(u8 *a0, f32 *a1) {
    V_45AC40 v, w, t;
    Q_45AC40 x, y;
    *(Q_45AC40 *)&t = 0;
    t.z = a1[1] + a1[0];
    *(Q_45AC40 *)&w = *(Q_45AC40 *)&t;
    func_0040C2D0(&w, &w, a0 + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_45AC40 *)(a0 + 0x10)));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
    if (func_003F9498(&v, *(s32 *)((u8 *)a1 + 0x38) & 2, a0, a1[0]) != 0) {
        *(s32 *)((u8 *)a1 + 0x84) = D_001EAA80.f18;
        *(Q_45AC40 *)((u8 *)a1 + 0x60) = D_001EAA80.f20;
        *(Q_45AC40 *)&v = D_001EAA80.f30;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V_45AC40 *)(a0 + 0x10)) : "j"(x));
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0045AC40 */
