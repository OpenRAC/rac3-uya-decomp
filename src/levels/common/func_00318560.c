#include "common.h"

/* localdecomp:start func_00318560 */
typedef int Q_318560 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_318560;
typedef struct {
    V4_318560 v0;
    f32 f10;
    f32 f14;
    s32 f18;
    s32 f1C;
    u8 pad[0x10];
} E_318560;
typedef struct {
    u8 pad[0x25C0];
    s32 f25C0;
} S_1A4BE0;
extern E_318560 D_002725C0[];
extern S_1A4BE0 D_001A4BE0;
extern void func_004C41E8(s32, V4_318560 *);
extern void func_0040CCA0(V4_318560 *, E_318560 *, V4_318560 *, f32);
extern void func_003186A8(s32, V4_318560 *, s32);
extern f32 func_0040CEC8(f32, f32);
extern void func_0040C0F0(V4_318560 *, V4_318560 *, f32);
extern s32 func_0040BA90(s32 *);
void func_00318560(s32 id) {
    V4_318560 t0;
    V4_318560 t10;
    Q_318560 qa, qb;
    E_318560 *p;
    s32 i;
    f32 t;
    for (i = 0; i < 12; i++) {
        p = &D_002725C0[i];
        if (p->f1C == id) {
            func_004C41E8(D_001A4BE0.f25C0 + 0x10, &t0);
            t = (f32)p->f18 / 37.0f;
            func_0040CCA0(&t10, p, &t0, p->f10);
            func_003186A8(id, &t10, (s32)(t * 128.0f));
            p->f10 = func_0040CEC8(p->f10, p->f14);
            func_0040C0F0(&t0, &t0, 0.04f);
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p->v0));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(t0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(p->v0) : "j"(qa));
            if (func_0040BA90(&p->f18)) {
                p->f1C = 0;
            }
        }
    }
}
/* localdecomp:end func_00318560 */
