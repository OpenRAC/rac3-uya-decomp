#include "common.h"

/* localdecomp:start func_003E2118 */
typedef int Q_3E2118 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3E2118;
typedef struct {
    u8 pad[0x28];
    f32 f28;
} E_3E2118;
typedef struct {
    u8 pad[0x10];
    V_3E2118 v10;
    u8 pad20[0x68 - 0x20];
    E_3E2118 *f68;
} O_3E2118;
extern void func_004C41E8(V_3E2118 *, V_3E2118 *);
extern void func_0040BE90(f32, V_3E2118 *, V_3E2118 *);
extern void func_004084B0(f32, f32, f32, V_3E2118 *, V_3E2118 *, s32, s32, s32, s32, s32, s32);
void func_003E2118(O_3E2118 *o) {
    E_3E2118 *e = o->f68;
    V_3E2118 a, c;
    Q_3E2118 x, y, r;
    if (e != 0) {
        e->f28 = e->f28 - 0.021f;
        if (e->f28 <= -8.0f) {
            e->f28 = e->f28 + 8.0f;
        }
        func_004C41E8(&o->v10, &a);
        func_0040BE90(1.9f, &a, &a);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(r));
        c = o->v10;
        func_004084B0(0.55f, 1.0f, e->f28, &c, &a, 0x1A, 1, 0x53FF7F40, 0x53FF7F40, 0xFF7F40, 0xFF7F40);
    }
}
/* localdecomp:end func_003E2118 */
