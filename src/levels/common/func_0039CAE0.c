#include "common.h"

/* localdecomp:start func_0039CAE0 */
typedef int Q_39CAE0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39CAE0;
typedef struct {
    f32 f0;
    u8 pad4[0xC];
    V4_39CAE0 v10;
    u8 v20[0x8];
    f32 f28;
    f32 f2c;
    struct { u8 pad[0x28]; f32 f28; } *e[4];
} S_39CAE0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x47];
    S_39CAE0 *s;
} O_39CAE0;
extern u8 D_001E2100;
extern void func_0040CCA0(void *, void *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
void func_0039CAE0(O_39CAE0 *o, V4_39CAE0 *out, s32 i) {
    S_39CAE0 *s = o->s;
    V4_39CAE0 t;
    Q_39CAE0 x, y;
    func_0040CCA0(&t, (u8 *)&D_001E2100 + i * 16, s->v20, s->f2c);
    if (s->e[i] != 0 && o->b20 == 2) {
        func_0040C0F0(&t, &t, s->e[i]->f28);
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->v10));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    out->z += s->f0;
}
/* localdecomp:end func_0039CAE0 */
