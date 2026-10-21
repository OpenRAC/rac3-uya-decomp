#include "common.h"

/* localdecomp:start func_0050D5B0 */
typedef struct {
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x25F4 - 0x80];
    u8 mode;
} Cam50D5B0;

extern Cam50D5B0 D_001A4BE0;
extern void func_0040C140(f32 *, f32 *, f32);
extern void func_0040C2F8(f32 *, f32 *, void *);

void func_0050D5B0(f32 *dst, f32 *src, f32 scale) {
    switch (D_001A4BE0.mode) {
    case 0:
        func_0040C140(dst, src, scale);
        break;
    case 1:
    case 2:
        func_0040C2F8(dst, src, D_001A4BE0.m1);
        func_0040C140(dst, dst, scale);
        func_0040C2F8(dst, dst, D_001A4BE0.m0);
        break;
    }
}
/* localdecomp:end func_0050D5B0 */
