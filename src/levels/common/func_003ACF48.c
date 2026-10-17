#include "common.h"
typedef struct { u8 pad[0x28]; s32 x28; s32 x2C; } V_3ACF48;
typedef struct { u8 pad[0x68]; V_3ACF48 *x68; } O_3ACF48;
extern u8 D_001E1D10[];
extern s32 func_00405420(s32);
extern void func_0044A4C8(u8 *, s32, s32, s32, s32);
void func_003ACF48(O_3ACF48 *o) {
    V_3ACF48 *v = o->x68;
    s32 n = v->x2C + 1;
    if (v->x28 < n) {
        n = v->x28;
    }
    func_0044A4C8(D_001E1D10, func_00405420(5072), n, v->x28, -1);
}
