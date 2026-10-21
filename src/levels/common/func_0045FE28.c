#include "common.h"

/* localdecomp:start func_0045FE28 */
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u32 w4;
    u8 pad8[2];
    s16 h10;
    u8 pad12[20];
    s32 w32;
} S45FE28;

extern u8 *D_0022111C[];
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(S45FE28 *);

void func_0045FE28(S45FE28 *a0) {
    a0->w4 = (a0->w4 & 0xFFFFFF) | ((a0->h10 * a0->w32 / 27) << 24);
    if (func_0040BAC0(&a0->h10)) {
        func_0045E580(a0);
        return;
    }
    a0->b2 = D_0022111C[0][(27 - a0->h10) / 3];
}
/* localdecomp:end func_0045FE28 */
