#include "common.h"

/* localdecomp:start func_00301DD8 */
typedef int Q_301DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_301DD8;
typedef struct {
    f32 f0;
    u8 pad4[0xC];
    V4_301DD8 v10;
    u8 pad20[0x8];
    f32 f28;
    f32 f2C;
    u8 pad30[0x4];
} Sub_301DD8;
extern V4_301DD8 D_0026ED10[];
extern void func_0040CCA0(void *, void *, f32, void *);
extern void func_0040C0F0(void *, void *, f32);
void func_00301DD8(u8 *obj, V4_301DD8 *out, s32 idx) {
    V4_301DD8 tmp __attribute__((aligned(16)));
    Q_301DD8 a, b, c;
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *q;
    func_0040CCA0(&tmp, &D_0026ED10[idx], *(f32 *)(p + 0x2C), p + 0x20);
    q = *(u8 **)((s32)p + (idx << 2) + 0x30);
    if (q != 0 && obj[0x20] == 2) {
        func_0040C0F0(&tmp, &tmp, *(f32 *)(q + 0x28));
    }
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_301DD8 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(tmp));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(c));
    out->z += *(f32 *)p;
}
/* localdecomp:end func_00301DD8 */
