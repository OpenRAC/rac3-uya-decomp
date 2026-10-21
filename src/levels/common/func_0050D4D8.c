#include "common.h"

/* localdecomp:start func_0050D4D8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50D4D8;
typedef struct {
    u8 pad0[64];
    Vec4_50D4D8 m;
    u8 pad50[9636];
    u8 b25F4;
} G_50D4D8;
extern G_50D4D8 D_001A4BE0;
extern void func_0040C2D0(Vec4_50D4D8 *, f32 *, Vec4_50D4D8 *);
f32 func_0050D4D8(f32 *a0) {
    Vec4_50D4D8 t;
    switch (D_001A4BE0.b25F4) {
    case 0:
        return a0[2];
    case 1:
    case 2:
        func_0040C2D0(&t, a0, &D_001A4BE0.m);
        return t.v[2];
    }
    return 0.0f;
}
/* localdecomp:end func_0050D4D8 */
