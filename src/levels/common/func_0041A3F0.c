#include "common.h"

/* localdecomp:start func_0041A3F0 */
extern void func_0041A3F0();

typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001DFD9C[];
s32 func_00419888(s32);
void func_0041A3F0(S_38ED00 *d, s32 a) {
    s32 i = func_00419888(a);
    if (i < 0) i = 0;
    d->x0 = D_001DFD9C[0][i].x0;
    d->x40 = i;
    d->x42 = D_001DFD9C[0][i].x6;
    d->x44 = D_001DFD9C[0][i].x4;

}
/* localdecomp:end func_0041A3F0 */
