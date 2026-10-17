#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad1[62];
    s16 b170;
    u8 pad2[84];
} Moby_0035E7A8;

extern u16 *D_0021CCE0[];
extern Moby_0035E7A8 *D_001DF71C;
extern s32 D_001DF758 __attribute__((section(".sdata")));

void func_0035E7A8(Moby_0035E7A8 *self) {
    u16 *p;
    Moby_0035E7A8 *m;

    if (((u8 *)self)[33] != 255) {
        p = D_0021CCE0[((u8 *)self)[33]];
        while (((u8 *)self)[33] != 255 && ((u8 *)self)[33] <= D_001DF758 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == D_0021CCE0[((u8 *)self)[33]])) {
            m = &D_001DF71C[*p & 0x7FFF];
            if (m == 0) break;
            if (m->b170 == self->b170) {
                *(s32 *)(m->vars + 736) = 1;
            }
            p++;
        }
    }
}
