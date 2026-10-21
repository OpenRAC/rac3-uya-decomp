#include "common.h"

/* localdecomp:start func_0045A1B0 */
typedef int Q_45A1B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_45A1B0;
typedef struct {
    u8 pad[0x10];
    V_45A1B0 v10;
    u8 pad20[0xE0 - 0x20];
    V_45A1B0 vE0;
} O_45A1B0;
extern V_45A1B0 D_001EAAC0;
extern void func_0040C0F0(f32, V_45A1B0 *, V_45A1B0 *);
extern void func_0040BE90(f32, V_45A1B0 *, V_45A1B0 *);
extern s32 func_003F8448(V_45A1B0 *, V_45A1B0 *, s32, O_45A1B0 *, s32);
void func_0045A1B0(O_45A1B0 *o, V_45A1B0 *out, s32 flag) {
    V_45A1B0 a, b;
    Q_45A1B0 x, y, r1, r2;
    func_0040C0F0(0.4f, &a, &o->vE0);
    func_0040C0F0(-3.0f, &b, &o->vE0);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(r2) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(r2));
    if (func_003F8448(&a, &b, 2, o, 0) != 0) {
        func_0040C0F0(1.0f, out, &D_001EAAC0);
    } else {
        func_0040C0F0(-1.0f, out, &o->vE0);
    }
    if (flag == 0) {
        func_0040BE90(-1.0f, out, out);
    }
}
/* localdecomp:end func_0045A1B0 */
