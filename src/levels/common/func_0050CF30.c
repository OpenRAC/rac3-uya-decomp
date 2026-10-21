#include "common.h"

typedef int Q_50CF30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_50CF30;
typedef struct {
    u8 pad0[0x2C0];
    u8 a2C0[0x20];
    u8 a2E0[0x2314];
    u8 b25F4;
} G_50CF30;
extern G_50CF30 D_001A4BE0;
extern void func_0040C0F0(void *, void *, f32);
extern void func_0050D5B0(void *, void *, f32);
extern void func_0050D530(void *, void *, f32);

/* localdecomp:start func_0050CF30 */
/* both cases are one macro on one source line: gcc cross-jumps their identical asm tails only if the asm statements share a line number */
#define BODY_50CF30(vec, a) { Q_50CF30 x, y, d, e; f32 z = 0.0f; func_0040C0F0(&t0, vec, a); func_0050D5B0(&t1, src, z); func_0050D530(obj, obj, z); __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t1)); __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*obj)); __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x)); __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t0)); __asm__("sqc2 %1, %0" : "=m"(*obj) : "j"(y)); __asm__("lqc2 %0, %1" : "=j"(e) : "m"(*obj)); __asm__("vadd.xyz %0, %0, %1" : "+j"(e) : "j"(d)); __asm__("sqc2 %1, %0" : "=m"(*obj) : "j"(e)); }

void func_0050CF30(V4_50CF30 *obj, f32 *src, f32 amt) {
    V4_50CF30 t0, t1;

    switch (D_001A4BE0.b25F4) {
    case 0:
        obj->z = src[2] - amt;
        break;
    case 1: BODY_50CF30(D_001A4BE0.a2C0, -amt) break; case 2: BODY_50CF30(D_001A4BE0.a2E0, amt) break;
    }
}
/* localdecomp:end func_0050CF30 */
